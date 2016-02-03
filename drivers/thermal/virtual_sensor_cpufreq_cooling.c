/*
 * virtual_sensor_cpufreq_cooling.c - virtual sensor cpu
 * cooler
 *
 * Copyright (C) 2015 Amazon, Inc.  All rights reserved.
 *
 * Author: Akwasi Boateng <boatenga@amazon.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */


#include <linux/cpu_cooling.h>
#include <linux/cpufreq.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/thermal.h>
#include <linux/cpumask.h>
#include <thermal_core.h>


/**
 * struct cpufreq_cooling_device - data for cooling device with cpufreq
 * @id: unique integer value corresponding to each cpufreq_cooling_device
 *registered.
 * @cool_dev: thermal_cooling_device pointer to keep track of the
 *registered cooling device.
 * @cpufreq_state: integer value representing the current state of cpufreq
 *coolingdevices.
 * @cpufreq_val: integer value representing the absolute value of the clipped
 *frequency.
 * @allowed_cpus: all the cpus involved for this cpufreq_cooling_device.
 *
 * This structure is required for keeping information of each
 * cpufreq_cooling_device registered. In order to prevent corruption of this a
 * mutex lock cooling_cpufreq_lock is used.
 */

struct cpufreq_cooling_device {
	int id;
	struct thermal_cooling_device *cool_dev;
	unsigned int cpufreq_state;
	unsigned int cpufreq_val;
	struct cpumask allowed_cpus;
	bool notify_device;
	struct notifier_block nb;
};

static ssize_t levels_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct thermal_cooling_device *cdev = container_of(dev, struct thermal_cooling_device, device);
	struct cpufreq_cooling_device *cpufreq_device;
	struct cpumask *mask;
	struct thermal_instance *instance;
	int offset = 0;
	unsigned int freq;
	unsigned int cpu;

	if (!cdev)
		return -EINVAL;
	cpufreq_device = (struct cpufreq_cooling_device *)cdev->devdata;
	if (!cpufreq_device)
		return -EINVAL;
	mask = &cpufreq_device->allowed_cpus;
	cpu = cpumask_any(mask);

	mutex_lock(&cdev->lock);
	list_for_each_entry(instance, &cdev->thermal_instances, cdev_node) {
		freq = cpufreq_cooling_get_frequency(cpu, instance->upper);
		offset += sprintf(buf + offset, "%d %d\n", instance->trip, freq);
	}
	mutex_unlock(&cdev->lock);
	return offset;
}

static ssize_t levels_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct thermal_cooling_device *cdev = container_of(dev, struct thermal_cooling_device, device);
	struct cpufreq_cooling_device *cpufreq_device;
	struct cpumask *mask;
	struct thermal_instance *instance;
	unsigned int freq, trip;
	unsigned long level;
	unsigned int cpu;

	if (!cdev)
		return -EINVAL;
	cpufreq_device = (struct cpufreq_cooling_device *)cdev->devdata;
	if (!cpufreq_device)
		return -EINVAL;
	mask = &cpufreq_device->allowed_cpus;
	cpu = cpumask_any(mask);

	if (sscanf(buf, "%d %d\n", &trip, &freq) != 2)
		return -EINVAL;
	if (trip >= THERMAL_MAX_TRIPS)
		return -EINVAL;

	mutex_lock(&cdev->lock);
	list_for_each_entry(instance, &cdev->thermal_instances, cdev_node) {
		if (instance->trip != trip)
			continue;
		level = cpufreq_cooling_get_level(cpu, freq);
		if (level == THERMAL_CSTATE_INVALID)
			return -EINVAL;
		instance->upper = level;
		instance->lower = instance->upper ? instance->upper - 1 : instance->upper;
	}
	mutex_unlock(&cdev->lock);

	return count;
}

static DEVICE_ATTR(levels, S_IRUGO | S_IWUSR, levels_show, levels_store);

static int virtual_sensor_cpufreq_cooling_probe(struct platform_device *pdev)
{
	struct thermal_cooling_device *cdev;
	struct cpumask mask_val;

	if (!cpufreq_frequency_get_table(0))
		return -EPROBE_DEFER;

	cpumask_set_cpu(0, &mask_val);
	cdev = cpufreq_cooling_register(&mask_val);

	if (IS_ERR(cdev)) {
		dev_err(&pdev->dev, "Failed to register cooling device\n");
		return PTR_ERR(cdev);
	}

	device_create_file(&cdev->device, &dev_attr_levels);
	platform_set_drvdata(pdev, cdev);

	dev_info(&pdev->dev, "Cooling device registered: %s\n",	cdev->type);

	return 0;
}

static int virtual_sensor_cpufreq_cooling_remove(struct platform_device *pdev)
{
	struct thermal_cooling_device *cdev = platform_get_drvdata(pdev);

	cpufreq_cooling_unregister(cdev);

	return 0;
}

static struct platform_driver virtual_sensor_cpufreq_cooling_driver = {
	.driver = {
		.owner = THIS_MODULE,
		.name = "virtual_sensor-cpufreq-cooling",
	},
	.probe = virtual_sensor_cpufreq_cooling_probe,
	.remove = virtual_sensor_cpufreq_cooling_remove,
};

static int __init virtual_sensor_cpufreq_cooling_init(void)
{
	return platform_driver_register(&virtual_sensor_cpufreq_cooling_driver);
}

static void __exit virtual_sensor_cpufreq_cooling_exit(void)
{
	platform_driver_unregister(&virtual_sensor_cpufreq_cooling_driver);
}

late_initcall(virtual_sensor_cpufreq_cooling_init);
module_exit(virtual_sensor_cpufreq_cooling_exit);

MODULE_AUTHOR("Akwasi Boateng <boatenga@amazon.com>");
MODULE_DESCRIPTION("VIRTUAL_SENSOR cpufreq cooling driver");
MODULE_LICENSE("GPL");
