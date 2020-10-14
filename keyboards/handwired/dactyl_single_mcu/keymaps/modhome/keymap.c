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


#define GUI_A       GUI_T(KC_A)
#define ALT_S       ALT_T(KC_S)
#define SFT_D       LSFT_T(KC_D)
#define CTL_F       CTL_T(KC_F)
#define CTL_J       CTL_T(KC_J)
#define SFT_K       RSFT_T(KC_K)
#define ALT_L       ALT_T(KC_L)
#define GU_SCLN     GUI_T(KC_SCLN)

#define KC_SINS     LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RSTDL ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  GUI_A ,  ALT_S ,  SFT_D ,  CTL_F ,   KC_G ,                             KC_H  ,  CTL_J ,  SFT_K ,  ALT_L , GU_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,                             KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
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
      LLOCK , XXXXXXX, KC_PGUP,  KC_UP , KC_PGDN, KC_HOME,                           KC_ASTR,  KC_7  ,  KC_8  ,  KC_9  , KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,                           KC_SLSH,  KC_4  ,  KC_5  ,  KC_6  , KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PSCR, XXXXXXX, KC_SPC , XXXXXXX, KC_SINS,                           KC_EQL ,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT , _______,
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
    case ALT_L:
        // This piece of code nullifies the effect of Right Shift when
        // tapping the K (colemak I) key. This helps rolling over colemak E and I 
        // to obtain the intended "ei" instead of "I". Consequently, capital I can 
        // only be obtained by holding d (colemak s) and tapping L (colemak i) (which is the left shift mod tap).
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RSHIFT)) {
                unregister_code(KC_RSHIFT);
                tap_code(KC_K);
                tap_code(KC_L);
                set_mods(mod_state);
                return false;
            }
        }
        // else process as usual.
      return true;
      break;
    case CTL_J:
        // This piece of code nullifies the effect of Right Shift when
        // tapping the J (colemak n) key. This helps rolling over colemak E and I 
        // to obtain the intended "ne" instead of "N". Consequently, capital N can 
        // only be obtained by holding d (colemak s) and tapping J (colemak n) (which is the left shift mod tap).
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RSHIFT)) {
                unregister_code(KC_RSHIFT);
                tap_code(KC_K);
                tap_code(KC_J);
                set_mods(mod_state);
                return false;
            }
        }
        // else process as usual.
      return true;
      break;
    case CTL_F:
        // This piece of code nullifies the effect of Left Shift when
        // tapping the F (colemak t) key. This helps rolling over colemak S and T 
        // to obtain the intended "st" instead of "T". Consequently, capital T can 
        // only be obtained by holding K (colemak e) and tapping F (colemak t) (which is the left shift mod tap).
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_LSHIFT)) {
                unregister_code(KC_LSHIFT);
                tap_code(KC_D);
                tap_code(KC_F);
                set_mods(mod_state);
                return false;
            }
        }
        // else process as usual.
      return true;
      break;
  }
  return true;
}

/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
            return TAPPING_TERM + 50;
        case GU_SCLN:
            return TAPPING_TERM + 50;
        case ALT_S:
            return TAPPING_TERM + 25;
        case ALT_L:
            return TAPPING_TERM + 25;
        case CTL_F:
            return TAPPING_TERM - 50;
        case CTL_J:
            return TAPPING_TERM - 50;
        case SFT_D:
            return TAPPING_TERM - 100;
        case SFT_K:
            return TAPPING_TERM - 100;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            case SFT_D:
                return false;
            case SFT_K:
                return false;
            default:
                return true;
        }
}
