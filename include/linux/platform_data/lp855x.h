/*
 * LP855x Backlight Driver
 *
 *			Copyright (C) 2011 Texas Instruments
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef _LP855X_H
#define _LP855X_H

#define BL_CTL_SHFT	(0)
#define BRT_MODE_SHFT	(1)
#define BRT_MODE_MASK	(0x06)

#define ENABLE_BL	(1)
#define DISABLE_BL	(0)

#define I2C_CONFIG(id)	id ## _I2C_CONFIG
#define PWM_CONFIG(id)	id ## _PWM_CONFIG

#define LP8550_PWM_CONFIG	(LP8550_PWM_ONLY << BRT_MODE_SHFT)
#define LP8550_I2C_CONFIG	((ENABLE_BL << BL_CTL_SHFT) | \
				(LP8550_I2C_ONLY << BRT_MODE_SHFT))

#define LP8551_PWM_CONFIG	LP8550_PWM_CONFIG
#define LP8551_I2C_CONFIG	LP8550_I2C_CONFIG

#define LP8552_PWM_CONFIG	LP8550_PWM_CONFIG
#define LP8552_I2C_CONFIG	LP8550_I2C_CONFIG

#define LP8553_PWM_CONFIG	LP8550_PWM_CONFIG
#define LP8553_I2C_CONFIG	LP8550_I2C_CONFIG

#define LP8555_PWM_STANDBY	BIT(7)
#define LP8555_PWM_FILTER	BIT(6)
#define LP8555_RELOAD_EPROM	BIT(3)	
#define LP8555_OFF_OPENLEDS	BIT(2)
#define LP8555_PWM_CONFIG	LP8555_PWM_ONLY
#define LP8555_I2C_CONFIG	LP8555_I2C_ONLY
#define LP8555_COMB1_CONFIG	LP8555_COMBINED1
#define LP8555_COMB2_CONFIG	LP8555_COMBINED2

#define LP8556_PWM_CONFIG	(LP8556_PWM_ONLY << BRT_MODE_SHFT)
#define LP8556_COMB1_CONFIG	(LP8556_COMBINED1 << BRT_MODE_SHFT)
#define LP8556_I2C_CONFIG	((ENABLE_BL << BL_CTL_SHFT) | \
				(LP8556_I2C_ONLY << BRT_MODE_SHFT))
#define LP8556_COMB2_CONFIG	(LP8556_COMBINED2 << BRT_MODE_SHFT)
#define LP8556_FAST_CONFIG	BIT(7) 

#define LP8557_PWM_STANDBY	BIT(7)
#define LP8557_PWM_FILTER	BIT(6)
#define LP8557_RELOAD_EPROM	BIT(3)	
#define LP8557_OFF_OPENLEDS	BIT(2)
#define LP8557_PWM_CONFIG	LP8557_PWM_ONLY
#define LP8557_I2C_CONFIG	LP8557_I2C_ONLY
#define LP8557_COMB1_CONFIG	LP8557_COMBINED1
#define LP8557_COMB2_CONFIG	LP8557_COMBINED2

enum lp855x_chip_id {
	LP8550,
	LP8551,
	LP8552,
	LP8553,
	LP8555,
	LP8556,
	LP8557,
};

enum lp8550_brighntess_source {
	LP8550_PWM_ONLY,
	LP8550_I2C_ONLY = 2,
};

enum lp8551_brighntess_source {
	LP8551_PWM_ONLY = LP8550_PWM_ONLY,
	LP8551_I2C_ONLY = LP8550_I2C_ONLY,
};

enum lp8552_brighntess_source {
	LP8552_PWM_ONLY = LP8550_PWM_ONLY,
	LP8552_I2C_ONLY = LP8550_I2C_ONLY,
};

enum lp8553_brighntess_source {
	LP8553_PWM_ONLY = LP8550_PWM_ONLY,
	LP8553_I2C_ONLY = LP8550_I2C_ONLY,
};

enum lp8555_brightness_source {
	LP8555_PWM_ONLY,
	LP8555_I2C_ONLY,
	LP8555_COMBINED1,	
	LP8555_COMBINED2,	
};

enum lp8556_brightness_source {
	LP8556_PWM_ONLY,
	LP8556_COMBINED1,	
	LP8556_I2C_ONLY,
	LP8556_COMBINED2,	
};

enum lp8557_brightness_source {
	LP8557_PWM_ONLY,
	LP8557_I2C_ONLY,
	LP8557_COMBINED1,	
	LP8557_COMBINED2,	
};

struct lp855x_rom_data {
	u8 addr;
	u8 val;
};

struct lp855x_platform_data {
	const char *name;
	u8 device_control;
	int initial_brightness;
	unsigned int period_ns;
	int size_program;
	struct lp855x_rom_data *rom_data;
	bool boot_on;
	int torch_brightness;
	bool use_htc_strobe;
};

#endif
