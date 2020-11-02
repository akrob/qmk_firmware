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
uint8_t mod_state; // variable holding the binary representation of active modifiers.

enum custom_keycodes {
  RIGHT = SAFE_RANGE,
  LEFT,
  RLOCK,
  LLOCK,
  RSTDL
};

// Mod holds:
#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define GUI_C       GUI_T(KC_C)
#define SFT_V       LSFT_T(KC_V)
#define SFT_M       RSFT_T(KC_M)
#define GU_COMM     GUI_T(KC_COMM)
#define ALT_DOT     ALT_T(KC_DOT)
#define CT_SLSH     CTL_T(KC_SLSH)

#define KC_SINS     LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RSTDL ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,   KC_G ,                             KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  CTL_Z ,  ALT_X ,  GUI_C ,  SFT_V  ,  KC_B  ,                            KC_N  ,  SFT_M , GU_COMM, ALT_DOT, CT_SLSH, KC_RSFT,
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
     XXXXXXX, KC_TILD, KC_GRV , KC_LBRC, KC_RBRC, XXXXXXX,                            KC_PGUP, KC_HOME,  KC_UP , KC_END , XXXXXXX,  RLOCK ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM,  KC_AT , KC_LPRN, KC_RPRN, KC_DLR ,                            KC_PGDN , KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_UNDS,
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
      LLOCK , XXXXXXX, KC_PGUP,  KC_UP , KC_PGDN, KC_HOME,                           KC_ASTR,  KC_7  ,  KC_8  ,  KC_9  , KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,                           KC_SLSH,  KC_4  ,  KC_5  ,  KC_6  , KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PSCR, XXXXXXX, KC_SPC , KC_ENT , KC_SINS,                           KC_EQL ,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT , _______,
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
  mod_state = get_mods();
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
    // Shift aid - disabling shift for problem bigrams
    // https://www.reddit.com/r/ErgoMechKeyboards/comments/ibsi0k/your_experiences_with_modlayer_tap/
    // https://github.com/precondition/qmk_firmware/blob/user-precondition/keyboards/handwired/dactyl_manuform/5x6/keymaps/precondition/keymap.c
    // case ALT_L:
    //     // This piece of code nullifies the effect of Right Shift when
    //     // tapping the K (colemak I) key. This helps rolling over colemak E and I
    //     // to obtain the intended "ei" instead of "I". Consequently, capital I can
    //     // only be obtained by holding d (colemak s) and tapping L (colemak i) (which is the left shift mod tap).
    //     if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
    //         if (mod_state & MOD_BIT(KC_RSHIFT)) {
    //             unregister_code(KC_RSHIFT);
    //             tap_code(KC_K);
    //             tap_code(KC_L);
    //             set_mods(mod_state);
    //             return false;
    //         }
    //     }
    //     // else process as usual.
    //   return true;
    //   break;
  }
  return true;
}

/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_Z:
            return TAPPING_TERM + 50;
        case CT_SLSH:
            return TAPPING_TERM + 50;
        case ALT_X:
            return TAPPING_TERM + 25;
        case ALT_DOT:
            return TAPPING_TERM + 25;
        case GUI_C:
            return TAPPING_TERM - 50;
        case GU_COMM:
            return TAPPING_TERM - 50;
        case SFT_V:
            return TAPPING_TERM - 100;
        case SFT_M:
            return TAPPING_TERM - 100;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            case SFT_V:
                return false;
            case SFT_M:
                return false;
            default:
                return true;
        }
}
