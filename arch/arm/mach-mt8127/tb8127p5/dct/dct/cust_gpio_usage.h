/*
 * Generated by MTK SP Drv_CodeGen Version 03.13.6  for MT8127. Copyright MediaTek Inc. (C) 2013.
 * Mon Jan 19 14:12:52 2015
 * Do Not Modify the File.
 */

#ifndef __CUST_GPIO_USAGE_H__
#define __CUST_GPIO_USAGE_H__


#define GPIO_PMIC_EINT_PIN         (GPIO2 | 0x80000000)
#define GPIO_PMIC_EINT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_PMIC_EINT_PIN_M_EINT  GPIO_PMIC_EINT_PIN_M_GPIO

#define GPIO_AUD_CLK_MOSI_PIN         (GPIO7 | 0x80000000)
#define GPIO_AUD_CLK_MOSI_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_AUD_CLK_MOSI_PIN_M_CLK  GPIO_MODE_01

#define GPIO_AUD_DAT_MISO_PIN         (GPIO8 | 0x80000000)
#define GPIO_AUD_DAT_MISO_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_AUD_DAT_MISO_PIN_M_AUD_MISO   GPIO_MODE_01

#define GPIO_AUD_DAT_MOSI_PIN         (GPIO9 | 0x80000000)
#define GPIO_AUD_DAT_MOSI_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_AUD_DAT_MOSI_PIN_M_AUD_MOSI   GPIO_MODE_01

#define GPIO_EINT_CHG_STAT_PIN         (GPIO23 | 0x80000000)
#define GPIO_EINT_CHG_STAT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_EINT_CHG_STAT_PIN_M_PWM  GPIO_MODE_01
#define GPIO_EINT_CHG_STAT_PIN_M_EINT  GPIO_EINT_CHG_STAT_PIN_M_GPIO

#define GPIO_ACCDET_EINT_PIN         (GPIO26 | 0x80000000)
#define GPIO_ACCDET_EINT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_ACCDET_EINT_PIN_M_CLK  GPIO_MODE_01
#define GPIO_ACCDET_EINT_PIN_M_EINT  GPIO_ACCDET_EINT_PIN_M_GPIO
#define GPIO_ACCDET_EINT_PIN_CLK     CLK_OUT2
#define GPIO_ACCDET_EINT_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_HDMI_POWER_CONTROL         (GPIO27 | 0x80000000)
#define GPIO_HDMI_POWER_CONTROL_M_GPIO  GPIO_MODE_00
#define GPIO_HDMI_POWER_CONTROL_M_KCOL  GPIO_MODE_06

#define GPIO_CTP_EINT_PIN         (GPIO35 | 0x80000000)
#define GPIO_CTP_EINT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_CTP_EINT_PIN_M_KROW  GPIO_MODE_01
#define GPIO_CTP_EINT_PIN_M_EINT  GPIO_CTP_EINT_PIN_M_GPIO

#define GPIO_OTG_DRVVBUS_PIN         (GPIO35 | 0x80000000)
#define GPIO_OTG_DRVVBUS_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_OTG_DRVVBUS_PIN_M_KROW  GPIO_MODE_01

#define GPIO_KPD_KCOL0_PIN         (GPIO36 | 0x80000000)
#define GPIO_KPD_KCOL0_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_KPD_KCOL0_PIN_M_KCOL  GPIO_MODE_01

#define GPIO_OTG_IDDIG_EINT_PIN         (GPIO38 | 0x80000000)
#define GPIO_OTG_IDDIG_EINT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_OTG_IDDIG_EINT_PIN_M_KCOL  GPIO_MODE_01
#define GPIO_OTG_IDDIG_EINT_PIN_M_IDDIG   GPIO_MODE_02

#define GPIO_CTP_RST_PIN         (GPIO45 | 0x80000000)
#define GPIO_CTP_RST_PIN_M_GPIO  GPIO_MODE_00

#define GPIO_GYRO_EINT_PIN         (GPIO50 | 0x80000000)
#define GPIO_GYRO_EINT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_GYRO_EINT_PIN_M_CLK  GPIO_MODE_02
#define GPIO_GYRO_EINT_PIN_M_EINT  GPIO_GYRO_EINT_PIN_M_GPIO
#define GPIO_GYRO_EINT_PIN_CLK     CLK_OUT3
#define GPIO_GYRO_EINT_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_GSE_1_EINT_PIN         (GPIO51 | 0x80000000)
#define GPIO_GSE_1_EINT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_GSE_1_EINT_PIN_M_CLK  GPIO_MODE_04
#define GPIO_GSE_1_EINT_PIN_M_EINT  GPIO_GSE_1_EINT_PIN_M_GPIO
#define GPIO_GSE_1_EINT_PIN_CLK     CLK_OUT1
#define GPIO_GSE_1_EINT_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_MSE_EINT_PIN         (GPIO52 | 0x80000000)
#define GPIO_MSE_EINT_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_MSE_EINT_PIN_M_CLK  GPIO_MODE_04
#define GPIO_MSE_EINT_PIN_CLK     CLK_OUT2
#define GPIO_MSE_EINT_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_CAMERA_CMRST_PIN         (GPIO53 | 0x80000000)
#define GPIO_CAMERA_CMRST_PIN_M_GPIO  GPIO_MODE_00

#define GPIO_CAMERA_CMPDN1_PIN         (GPIO54 | 0x80000000)
#define GPIO_CAMERA_CMPDN1_PIN_M_GPIO  GPIO_MODE_00

#define GPIO_CAMERA_CMRST1_PIN         (GPIO55 | 0x80000000)
#define GPIO_CAMERA_CMRST1_PIN_M_GPIO  GPIO_MODE_00

#define GPIO_CAMERA_CMPDN_PIN         (GPIO56 | 0x80000000)
#define GPIO_CAMERA_CMPDN_PIN_M_GPIO  GPIO_MODE_00

#define GPIO_I2C1_SDA_PIN         (GPIO57 | 0x80000000)
#define GPIO_I2C1_SDA_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_I2C1_SDA_PIN_M_SDA   GPIO_MODE_01

#define GPIO_I2C1_SCA_PIN         (GPIO58 | 0x80000000)
#define GPIO_I2C1_SCA_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_I2C1_SCA_PIN_M_SCL   GPIO_MODE_01

#define GPIO_I2C0_SDA_PIN         (GPIO75 | 0x80000000)
#define GPIO_I2C0_SDA_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_I2C0_SDA_PIN_M_SDA   GPIO_MODE_01

#define GPIO_I2C0_SCA_PIN         (GPIO76 | 0x80000000)
#define GPIO_I2C0_SCA_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_I2C0_SCA_PIN_M_SCL   GPIO_MODE_01

#define GPIO_UART_URXD1_PIN         (GPIO79 | 0x80000000)
#define GPIO_UART_URXD1_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_UART_URXD1_PIN_M_URXD   GPIO_MODE_01

#define GPIO_UART_UTXD1_PIN         (GPIO80 | 0x80000000)
#define GPIO_UART_UTXD1_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_UART_UTXD1_PIN_M_UTXD   GPIO_MODE_01

#define GPIO_LCM_RST         (GPIO83 | 0x80000000)
#define GPIO_LCM_RST_M_GPIO  GPIO_MODE_00

#define GPIO_LCM_PWR         (GPIO84 | 0x80000000)
#define GPIO_LCM_PWR_M_GPIO  GPIO_MODE_00

#define GPIO_CAMERA_FLASH_EN_PIN         (GPIO117 | 0x80000000)
#define GPIO_CAMERA_FLASH_EN_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_CAMERA_FLASH_EN_PIN_M_ANT_SEL   GPIO_MODE_03

#define GPIO_GPS_LNA_PIN         (GPIO118 | 0x80000000)
#define GPIO_GPS_LNA_PIN_M_GPIO  GPIO_MODE_00
#define GPIO_GPS_LNA_PIN_M_CMDAT   GPIO_MODE_01
#define GPIO_GPS_LNA_PIN_M_CMCSD   GPIO_MODE_02
#define GPIO_GPS_LNA_PIN_M_ANT_SEL   GPIO_MODE_03
#define GPIO_GPS_LNA_PIN_M_DBG_MON_B   GPIO_MODE_07


/*Output for default variable names*/
/*@XXX_XX_PIN in gpio.cmp          */




/*Output for default variable names*/
/*@XXX_XX_PIN in gpio.cmp          */



#endif /* __CUST_GPIO_USAGE_H__ */


