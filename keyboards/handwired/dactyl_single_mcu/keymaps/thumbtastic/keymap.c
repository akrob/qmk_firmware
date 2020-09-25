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
#define _RIGHT 1
#define _LEFT 2
#define _DUAL 3

// Used for Custom Tap/Hold for layers
#define KEY_DELAY 150
static uint16_t key_timer;
#define RESET_DELAY 5000
static uint16_t reset_timer;
bool rlocked = false;
bool llocked = false;

enum custom_keycodes {
  RIGHT = SAFE_RANGE,
  LEFT,
  RLOCK,
  LLOCK,
  RSTDL
};

#define ALT_DOT     ALT_T(KC_DOT)
#define ALT_X       ALT_T(KC_X)
#define CT_SLSH    CTL_T(KC_SLSH)
#define CTL_Z       CTL_T(KC_Z)
#define GUI_C       GUI_T(KC_C)
#define GU_COMM    GUI_T(KC_COMM)
#define KC_SINS LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RSTDL ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                             KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  CTL_Z ,  ALT_X ,  GUI_C ,  KC_V  ,  KC_B  ,                             KC_N  ,  KC_M  , GU_COMM, ALT_DOT, CT_SLSH, KC_RSFT,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       XXXXXXX, XXXXXXX,                                                                XXXXXXX, XXXXXXX,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                           LEFT , KC_BSPC,                            KC_SPC ,  RIGHT ,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             XXXXXXX, KC_DEL ,                   KC_ENT , XXXXXXX,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                 XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_RIGHT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, KC_TILD, KC_GRV , KC_LBRC, KC_RBRC, XXXXXXX,                            KC_HOME, KC_PGUP,  KC_UP , KC_PGDN, XXXXXXX,  RLOCK ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM,  KC_AT , KC_LPRN, KC_RPRN, KC_DLR ,                            KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_UNDS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_PERC, KC_LCBR, KC_RCBR, XXXXXXX,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL , _______,
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
  [_LEFT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
      LLOCK , XXXXXXX, XXXXXXX,  KC_UP ,  KC_F5 , XXXXXXX,                           KC_ASTR,  KC_7  ,  KC_8  ,  KC_9  , KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT ,                           KC_SLSH,  KC_4  ,  KC_5  ,  KC_6  , KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PSCR, KC_DEL , KC_BSPC, KC_SINS, KC_SPC ,                           KC_EQL ,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT , _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                         └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                               _______, _______,
  //                  └────────┴────────┼────────┬────────┐                         ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            KC_0  , _______,
  //                                    └───┬────┴───┬────┴───┐                ┌────┴───┬────┴───┬────┘
                                             _______, _______,                  _______, _______,
  //                                        └───┬────┴───┬────┴───┐       ┌────┴───┬────┴───┬────┘
                                                 _______, _______,         _______, _______
  //                                            └────────┴────────┘       └────────┴────────┘
  ),
  [_DUAL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                             KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, KC_BTN1,                            KC_BTN2, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, XXXXXXX,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            _______, _______,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                 _______, _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  )
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
    case RIGHT:
      if (record->event.pressed){
        rlocked = false;
        layer_on(_RIGHT);
        update_tri_layer(_RIGHT, _LEFT, _DUAL);
      } else {
        if (rlocked  == false){
          layer_off(_RIGHT);
          update_tri_layer(_RIGHT, _LEFT, _DUAL);
        }
      }
      return false;
      break;
    case LEFT:
      if (record->event.pressed){
        llocked = false;
        key_timer = timer_read(); // if the key is being pressed, we start the timer.
        layer_on(_LEFT);
        update_tri_layer(_RIGHT, _LEFT, _DUAL);
      } else {
        // This enables TAP vs HOLD behavior
        if (timer_elapsed(key_timer) < KEY_DELAY) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
        if (llocked == false){
          layer_off(_LEFT);
          update_tri_layer(_RIGHT, _LEFT, _DUAL);
        }
      }
      return false;
      break;
    case RLOCK:
      if (record->event.pressed) {
        rlocked = true;
      }
      return false;
      break;
    case LLOCK:
      if (record->event.pressed) {
        llocked = true;
      }
      return false;
      break;
    case RSTDL:
      if (record->event.pressed){
        reset_timer = timer_read(); // if the key is being pressed, we start the timer.
      } else {
        // only RESET if it is REALLY being held 5+ seconds
        // This enables TAP vs HOLD behavior
        if (timer_elapsed(reset_timer) > RESET_DELAY) {
          reset_keyboard();
        } else {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
