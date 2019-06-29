/* Copyright 2019 Atomantium
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, \
    k10, k11, k12, k13, k14, k15, \
    k20, k21, k22, k23, k24, k25, \
              k32, k33, \
        k42, k43, \
    k40, k41, \
    k30, k31  \
) \
{ \
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, k11, k12, k13, k14, k15 }, \
    { k20, k21, k22, k23, k24, k25 }, \
    { KC_NO, KC_NO, k40, k41, k42, k43 }, \
    { KC_NO, KC_NO, k30, k31, k32, k33 }, \
}
  /*
    { k40, k41, k42, k43, KC_NO, KC_NO }, \
    { k40, k41, k42, k43, KC_NO, KC_NO }, \
    */
/*
{ \
    { k00, k10, k20, k40, k30 }, \
    { k01, k11, k21, k41, k31 }, \
    { k02, k12, k22, k43, k32 }, \
    { k03, k13, k23, k43, k33 }, \
    { k04, k14, k24, KC_NO, KC_NO }, \
    { k05, k15, k25, KC_NO, KC_NO }, \
}
*/
