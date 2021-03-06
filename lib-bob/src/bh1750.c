/**
 * @file bh1750.c
 *
 */
/* Copyright (C) 2017-2018 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>

#if defined(__linux__) || defined (__circle__)
 #include "bcm2835.h"
#else
 #include "bcm2835_i2c.h"
#endif

#include "i2c.h"

#include "bh1750.h"

#include "device_info.h"

#define BH1750_POWER_DOWN					0x00	///<
#define BH1750_POWER_ON						0x01	///<
#define BH1750_RESET						0x07	///<
#define BH1750_CONTINUOUS_HIGH_RES_MODE 	0x10	///<
#define BH1750_CONTINUOUS_HIGH_RES_MODE_2 	0x11	///<
#define BH1750_CONTINUOUS_LOW_RES_MODE		0x13	///<
#define BH1750_ONE_TIME_HIGH_RES_MODE		0x20	///<
#define BH1750_ONE_TIME_HIGH_RES_MODE_2		0x21	///<
#define BH1750_ONE_TIME_LOW_RES_MODE		0x23	///<

static void i2c_setup(const device_info_t *device_info) {
	bcm2835_i2c_setSlaveAddress(device_info->slave_address);

	if (device_info->fast_mode) {
		bcm2835_i2c_setClockDivider(BCM2835_I2C_CLOCK_DIVIDER_626);
	} else {
		bcm2835_i2c_setClockDivider(BCM2835_I2C_CLOCK_DIVIDER_2500);
	}
}

const bool bh1750_start(device_info_t *device_info) {
	char buf;

	bcm2835_i2c_begin();

	if (device_info->slave_address == (uint8_t) 0) {
		device_info->slave_address = BH1750_I2C_DEFAULT_SLAVE_ADDRESS;
	}

	if (device_info->speed_hz == (uint32_t) 0) {
		device_info->fast_mode = true;
	}

	i2c_setup(device_info);

	if (!i2c_is_connected(device_info->slave_address)) {
		return false;
	}

	buf = BH1750_CONTINUOUS_HIGH_RES_MODE;
	(void) bcm2835_i2c_write(&buf, 1);

	return true;
}

const uint16_t bh1750_get_level(const device_info_t *device_info) {
	uint16_t level;

	i2c_setup(device_info);

	level = (float) i2c_read_uint16() / (float) 1.2;

	return level;
}
