/*
 * Copyright (C) Kris Kwiatkowski, Among Bytes LTD
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <platform/platform.h>
#include <platform/printf.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

int main(void) {
    size_t                 i = 0;
    struct platform_attr_t a;
    uint8_t                buf[32] = { 0 };
    bool                   r;

    platform_init(PLATFORM_CLOCK_MAX);

    // Check if cycle counting works
    uint64_t t = platform_cpu_cyclecount();
    i++;
    t = platform_cpu_cyclecount() - t;
    printf("\n Hello world.\n");
    printf("\n Cycle count: %llu.\n", t);

    // Check getting a random number
    platform_get_random(buf, sizeof(buf));
    printf("RNG1: ");
    for (i = 0; i < sizeof(buf); i++) {
        printf("%02x", buf[i]);
    }
    printf("\n");

    // Trigger up
    a.attr[0] = PLATFORM_SCA_TRIGGER_HIGH;
    a.n       = 1;
    r         = platform_set_attr(&a);
    printf("Trigger high set: %d\n", r ? 1 : 0);

    a.attr[0] = PLATFORM_SCA_TRIGGER_LOW;
    a.n       = 1;
    r         = platform_set_attr(&a);
    printf("Trigger low set: %d\n", r ? 1 : 0);

    return 0;
}
