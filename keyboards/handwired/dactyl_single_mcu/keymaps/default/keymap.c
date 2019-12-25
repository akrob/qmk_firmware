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
#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _COLEMAK 1
#define _NAV 2
#define _NUMSYM 3
#define _FNUM 4
#define _NUMPAD 5
#define _MOUSE 6

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define ALT_DOT     ALT_T(KC_DOT)
#define ALT_X       ALT_T(KC_X)

#define CTL_SLSH    CTL_T(KC_SLSH)
#define CTL_Z       CTL_T(KC_Z)

#define GUI_C       GUI_T(KC_C)
#define GUI_COMM    GUI_T(KC_COMM)


#define T_NSDEL LT(_NUMSYM, KC_DEL)
#define T_NPTAB LT(_MOUSE, KC_TAB)
#define KC_SINS LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                             KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  CTL_Z ,  ALT_X ,  GUI_C ,  KC_V  ,  KC_B  ,                             KC_N  ,  KC_M  ,GUI_COMM, ALT_DOT,CTL_SLSH, KC_RSFT,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       KC_LPRN, KC_RPRN,                                                                KC_LBRC, KC_RBRC,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         T_NSDEL, KC_BSPC,                            KC_SPC , MO(_NAV),
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                              KC_NO , T_NPTAB,                   KC_ENT , KC_NO  ,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET ,  KC_NO ,           KC_NO ,  KC_NO
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                            KC_HOME, KC_PGUP,  KC_UP , KC_PGDN, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,                            KC_END , KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         KC_DEL , _______,                            _______, _______,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_NUMSYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_FNUM),                           KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                             KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL , KC_UNDS,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            _______,TG(_NUMPAD),
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_FNUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_FNUM),                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                             KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            _______, _______,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                            KC_ASTR,  KC_7  ,  KC_8  ,  KC_9  , KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                            KC_SLSH,  KC_4  ,  KC_5  ,  KC_6  , KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                            KC_EQL ,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT , _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                             KC_0  ,TG(_NUMPAD),
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , XXXXXXX, XXXXXXX,  KC_UP ,  KC_F5 , XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT ,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, XXXXXXX, KC_BSPC, KC_SINS, KC_SPC ,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            _______, _______,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
/*
  [_TEMPLATE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            _______, _______,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                 _______, _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
