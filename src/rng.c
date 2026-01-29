// SPDX-FileCopyrightText: 2026 AmongBytes, Ltd.
// SPDX-FileContributor: Kris Kwiatkowski <kris@amongbytes.com>
// SPDX-License-Identifier: LicenseRef-Proprietary

#include <stdint.h>

#include "stm32f2xx_hal_rcc.h"

/* xorshift32 state must be non-zero */
static uint32_t xs32_state = 0xA5A5A5A5u;

static inline void xorshift32_seed(uint32_t seed) {
    if (!seed) {
        seed = 0xA5A5A5A5u;
    }
    xs32_state = seed;
}

uint32_t xorshift32_u32(void) {
    uint32_t x = xs32_state;
    x          ^= x << 13;
    x          ^= x >> 17;
    x          ^= x << 5;
    xs32_state = x;
    return x;
}

void setup_rng(void) {
    uint32_t t    = SysTick->VAL;
    uint32_t uid0 = *(volatile uint32_t *)0x1FFF7A10;
    uint32_t uid1 = *(volatile uint32_t *)0x1FFF7A14;
    uint32_t uid2 = *(volatile uint32_t *)0x1FFF7A18;
    uint32_t s    = t ^ uid0 ^ (uid1 << 1) ^ (uid2 << 2);
    xorshift32_seed(s);
}
