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
//#define _COLEMAK 1
#define _RIGHT 2
#define _LEFT 3
#define _DUAL 4

// Used for Custom Tap/Hold for layers
#define KEY_DELAY 150
static uint16_t key_timer;

enum custom_keycodes {
  RIGHT,
  LEFT
};

#define ALT_DOT     ALT_T(KC_DOT)
#define ALT_X       ALT_T(KC_X)
#define CT_SLSH    CTL_T(KC_SLSH)
#define CTL_Z       CTL_T(KC_Z)
#define GUI_C       GUI_T(KC_C)
#define GU_COMM    GUI_T(KC_COMM)


//#define T_NSDEL LT(_LEFT, KC_DEL)
//#define T_NPTAB LT(_MOUSE, KC_TAB)
#define KC_SINS LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                             KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  CTL_Z ,  ALT_X ,  GUI_C ,  KC_V  ,  KC_B  ,                             KC_N  ,  KC_M  , GU_COMM, ALT_DOT, CT_SLSH, KC_RSFT,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       KC_LPRN, KC_RPRN,                                                                KC_LBRC, KC_RBRC,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                           LEFT , KC_BSPC,                            KC_SPC ,  RIGHT ,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                              KC_NO , KC_LEAD,                   KC_ENT , KC_NO  ,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET ,  KC_NO ,           KC_NO ,  KC_NO
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_RIGHT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , KC_TILD, KC_GRV , KC_LBRC, KC_RBRC, XXXXXXX,                            KC_HOME, KC_PGUP,  KC_UP , KC_PGDN, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM,  KC_AT , KC_LPRN, KC_RPRN, KC_DLR ,                            KC_END , KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_UNDS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_PERC, KC_LCBR, KC_RCBR, XXXXXXX,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_EQL , _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, KC_DEL ,                            _______, _______,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,          _______, _______
  //                                            └────────┴────────┘        └────────┴────────┘
  ),
  [_LEFT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , XXXXXXX, XXXXXXX,  KC_UP ,  KC_F5 , XXXXXXX,                            KC_ASTR,  KC_7  ,  KC_8  ,  KC_9  , KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT ,                            KC_SLSH,  KC_4  ,  KC_5  ,  KC_6  , KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PSCR, KC_DEL , KC_BSPC, KC_SINS, KC_SPC ,                            KC_EQL ,  KC_1  ,  KC_2  ,  KC_3  , KC_DOT , _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                         └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                               _______, _______,
  //                  └────────┴────────┼────────┬────────┐                         ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            KC_0  , _______,
  //                                    └───┬────┴───┬────┴───┐                ┌────┴───┬────┴───┬────┘
                                             _______, _______,                  _______, _______,
  //                                        └───┬────┴───┬────┴───┐       ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,         _______, _______
  //                                            └────────┴────────┘       └────────┴────────┘
  ),
  [_DUAL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                             KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, _______,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                          └────────┴────────┼────────┼────────┼────────┴────────┘
                       _______, _______,                                                                _______, _______,
  //                  └────────┴────────┼────────┬────────┐                          ┌────────┬────────┼────────┴────────┘
                                         _______, _______,                            _______, _______,
  //                                    └───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┘
                                             _______, _______,                   _______, _______,
  //                                        └───┬────┴───┬────┴───┐        ┌────┴───┬────┴───┬────┘
                                                  RESET , _______,          _______, _______
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
        layer_on(_RIGHT);
        update_tri_layer(_RIGHT, _LEFT, _DUAL);
      } else {
        layer_off(_RIGHT);
        update_tri_layer(_RIGHT, _LEFT, _DUAL);
      }
      return false;
      break;
    case LEFT:
      if (record->event.pressed){
        key_timer = timer_read(); // if the key is being pressed, we start the timer.
        layer_on(_LEFT);
        update_tri_layer(_RIGHT, _LEFT, _DUAL);
      } else {
        // This enables TAP vs HOLD behavior
        if (timer_elapsed(key_timer) < KEY_DELAY) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
        layer_off(_LEFT);
        update_tri_layer(_RIGHT, _LEFT, _DUAL);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_A) {
      register_code(KC_CAPS);
      register_code(KC_A);
      unregister_code(KC_A);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_B) {
      register_code(KC_CAPS);
      register_code(KC_B);
      unregister_code(KC_B);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_C) {
      register_code(KC_CAPS);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_D) {
      register_code(KC_CAPS);
      register_code(KC_D);
      unregister_code(KC_D);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_E) {
      register_code(KC_CAPS);
      register_code(KC_E);
      unregister_code(KC_E);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_F) {
      register_code(KC_CAPS);
      register_code(KC_F);
      unregister_code(KC_F);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_G) {
      register_code(KC_CAPS);
      register_code(KC_G);
      unregister_code(KC_G);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_H) {
      register_code(KC_CAPS);
      register_code(KC_H);
      unregister_code(KC_H);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_I) {
      register_code(KC_CAPS);
      register_code(KC_I);
      unregister_code(KC_I);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_J) {
      register_code(KC_CAPS);
      register_code(KC_J);
      unregister_code(KC_J);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_K) {
      register_code(KC_CAPS);
      register_code(KC_K);
      unregister_code(KC_K);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_L) {
      register_code(KC_CAPS);
      register_code(KC_L);
      unregister_code(KC_L);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_M) {
      register_code(KC_CAPS);
      register_code(KC_M);
      unregister_code(KC_M);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_N) {
      register_code(KC_CAPS);
      register_code(KC_N);
      unregister_code(KC_N);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_O) {
      register_code(KC_CAPS);
      register_code(KC_O);
      unregister_code(KC_O);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_P) {
      register_code(KC_CAPS);
      register_code(KC_P);
      unregister_code(KC_P);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_Q) {
      register_code(KC_CAPS);
      register_code(KC_Q);
      unregister_code(KC_Q);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_R) {
      register_code(KC_CAPS);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_S) {
      register_code(KC_CAPS);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_T) {
      register_code(KC_CAPS);
      register_code(KC_T);
      unregister_code(KC_T);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_U) {
      register_code(KC_CAPS);
      register_code(KC_U);
      unregister_code(KC_U);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_V) {
      register_code(KC_CAPS);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_W) {
      register_code(KC_CAPS);
      register_code(KC_W);
      unregister_code(KC_W);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_X) {
      register_code(KC_CAPS);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_Y) {
      register_code(KC_CAPS);
      register_code(KC_Y);
      unregister_code(KC_Y);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_Z) {
      register_code(KC_CAPS);
      register_code(KC_Z);
      unregister_code(KC_Z);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_TAB) {
      register_code(KC_CAPS);
      register_code(KC_TAB);
      unregister_code(KC_TAB);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_SPACE) {
      register_code(KC_CAPS);
      register_code(KC_SPACE);
      unregister_code(KC_SPACE);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_SCLN) {
      register_code(KC_CAPS);
      register_code(KC_SCLN);
      unregister_code(KC_SCLN);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_COMM) {
      register_code(KC_CAPS);
      register_code(KC_COMM);
      unregister_code(KC_COMM);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_DOT) {
      register_code(KC_CAPS);
      register_code(KC_DOT);
      unregister_code(KC_DOT);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_SLSH) {
      register_code(KC_CAPS);
      register_code(KC_SLSH);
      unregister_code(KC_SLSH);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_BSLS) {
      register_code(KC_CAPS);
      register_code(KC_BSLS);
      unregister_code(KC_BSLS);
      unregister_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_QUOT) {
      register_code(KC_CAPS);
      register_code(KC_QUOT);
      unregister_code(KC_QUOT);
      unregister_code(KC_CAPS);
    }
  }
}

void led_set_user(uint8_t usb_led) {

}
