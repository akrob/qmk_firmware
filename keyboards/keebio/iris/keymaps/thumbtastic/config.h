/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */

//#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8


// This makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when
// you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISIVE_HOLD
#define TAPPING_TERM 185
//#define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING

#undef NO_DEBUG
#define NO_DEBUG
#undef NO_PRINT
#define NO_PRINT
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_USB_STARTUP_CHECK

// LEADER KEY
#define LEADER_TIMEOUT 400
