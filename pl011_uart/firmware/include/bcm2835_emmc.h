/**
 * @file bcm2835_emmc.h
 *
 */
/* Copyright (C) 2014 by Arjan van Vught <pm @ http://www.raspberrypi.org/forum/>
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

#ifndef BCM2835_EMMC_H_
#define BCM2835_EMMC_H_

#include "stdint.h"

#define  BCM2835_EMMC_STATUS_CMD_INHIBIT	0x00000001	///< SDHCI_PRESENT_STATE 0x24, SDHCI_CMD_INHIBIT 0x00000001
#define  BCM2835_EMMC_STATUS_DATA_INHIBIT	0x00000002	///< SDHCI_PRESENT_STATE 0x24, SDHCI_DATA_INHIBIT 0x00000002

// CONTROL0, offset 0x28
#define BCM2835_EMMC_CONTROL0_POWER_ON		((uint32_t)(1 << 8))	///< SDHCI_POWER_CONTROL 0x29, SDHCI_POWER_ON 0x01

// CONTROL1, offset 0x2C
#define BCM2835_EMMC_CONTROL1_RESET_ALL 	((uint32_t)(1 << 24))	///< SDHCI_SOFTWARE_RESET 0x2F, SDHCI_RESET_ALL 0x01
#define BCM2835_EMMC_CONTROL1_RESET_CMD 	((uint32_t)(1 << 25))	///< SDHCI_SOFTWARE_RESET 0x2F, SDHCI_RESET_CMD 0x02
#define BCM2835_EMMC_CONTROL1_RESET_DATA	((uint32_t)(1 << 26))	///< SDHCI_SOFTWARE_RESET 0x2F, SDHCI_RESET_DATA 0x04

#endif /* BCM2835_EMMC_H_ */
