/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
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

#define USE_SERIAL

#define MASTER_LEFT
//#define MASTER_RIGHT
//#define EE_HANDS
// Rows are doubled-up

// Everything above this was in the default configuration for the dactyl manuform

//#ifndef CONFIG_BLAKEDIETZ_H
//#define CONFIG_BLAKEDIETZ_H

// Define mousekey settings
//#undef MOUSEKEY_DELAY
//#undef MOUSEKEY_INTERVAL
//#undef MOUSEKEY_MAX_SPEED
//#undef MOUSEKEY_TIME_TO_MAX
//#undef MOUSEKEY_WHEEL_DELAY

//#define MOUSEKEY_DELAY          0
//#define MOUSEKEY_INTERVAL       20
//#define MOUSEKEY_MAX_SPEED      2
//#define MOUSEKEY_TIME_TO_MAX    5
//#define MOUSEKEY_WHEEL_DELAY    0


// This makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when
// you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)
//#undef  IGNORE_MOD_TAP_INTERRUPT
//#define IGNORE_MOD_TAP_INTERRUPT

//#endif
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISIVE_HOLD
#define TAPPING_TERM 75
#define TAPPING_FORCE_HOLD
#define RETRO_TAPPING

