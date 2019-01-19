#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _QWERTY 1
#define _NAV 2
#define _NUMSYM 3
#define _SYMNUM 4
#define _MOUSE 5
#define _NUMPAD 6
#define _MEDIA 7
#define _X1 8
#define _X1RLAYER 9
#define _CONFIG 10


enum custom_keycodes {
  COLEMAK = SAFE_RANGE,        // qwerty base layer
  QWERTY,                    // colemak base layer
  NAV,
  NUMSYM,
  SYMNUM,
  MOUSE,
  NUMPAD,
  MEDIA,
  X1,                         // x1 carbon base layer
  X1RLAYER,                   // x1 carbon right layer
  CONFIG,                     // config layer
  LEDUP,                      // custom LED brightness increase keycode
  LEDDOWN,                    // custom LED brightness decrease keycode
};

/* Tap Dance */
enum {
  TD_LGUIAPP,                 // LGUI x1, app/menu x2
  TD_SHIFTCAPS,               // LSHIFT x1, CAPS x3
  TD_SHIFTX1CAPS,               // LSHIFT x1, LCTL x3 (for x1 carbon layer)
  TD_CTRLALTDL,               // CTRL+ALT+DEL x3
  TD_SHIFTCLAT,               // LSHIFT x1, LCRTL x2, LALT x3, CTRL+ALT x4
  TD_SHIFTX1CLAT,             // RSHIFT x1, LCAPS x2, LALT x3, CTRL+ALT x4 (for x1 carbon layer)
};

/* NOOP Key and Transparent */
#define KC_     KC_TRNS
#define KC_XXXX KC_NO

/* LAYERS / CUSTOM KEYS */
#define KC_COLE COLEMAK
#define KC_QWER QWERTY
#define KC_X1   X1
#define KC_CONF CONFIG
#define KC_BLUP LEDUP
#define KC_BLDN LEDDOWN

/* Custom Shortened Keys (4 digits so they fit in my grid) */
#define KC_MCTB LCTL(KC_TAB)
#define KC_MCST LCTL(LSFT(KC_TAB))
#define KC_CTEC CTL_T(KC_ESC)
#define KC_SINS LSFT(KC_INS)
#define KC_LGU1 LGUI(KC_1)
#define KC_LGU2 LGUI(KC_2)
#define KC_LGU3 LGUI(KC_3)
#define KC_LGU4 LGUI(KC_4)
#define KC_LGU5 LGUI(KC_5)
#define KC_LGU6 LGUI(KC_6)
#define KC_LGU7 LGUI(KC_7)
#define KC_LGU8 LGUI(KC_8)
#define KC_LGU9 LGUI(KC_9)
#define KC_LGU0 LGUI(KC_0)
#define KC_SYSR KC_SYSREQ
#define KC_REST RESET
#define KC_CAGE LCAG_T(KC_ESC)
#define KC_CAGQ RCAG_T(KC_QUOT)
#define KC_CTLZ CTL_T(KC_Z)
#define KC_CTSL CTL_T(KC_SLSH)
#define KC_ALTX ALT_T(KC_X)
#define KC_ALDT ALT_T(KC_DOT)
#define KC_GUIC GUI_T(KC_C)
#define KC_GUCM GUI_T(KC_COMM)
/* Layer Toggle Combos */
#define KC_TSNV LT(_NAV, KC_SPC)
#define KC_TTSN LT(_SYMNUM, KC_TAB)
#define KC_TDNS LT(_NUMSYM, KC_DEL)
#define KC_TTNP LT(_NUMPAD, KC_TAB)
#define KC_TBMS LT(_MOUSE, KC_BSPC)

/* Tap Dance */
#define KC_LGUA TD(TD_LGUIAPP)
#define KC_SHCP TD(TD_SHIFTCAPS)
#define KC_XSCP TD(TD_SHIFTX1CAPS)
#define KC_CADL TD(TD_CTRLALTDL)
#define KC_SHCA TD(TD_SHIFTCLAT)
#define KC_XSCA TD(TD_SHIFTX1CLAT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     EQL , Q  , W  , F  , P  , G  ,                J  , L  , U  , Y  ,SCLN,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAGE, A  , R  , S  , T  , D  ,                H  , N  , E  , I  , O  ,CAGQ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SHCP,CTLZ,ALTX,GUIC, V  , B  ,CONF,     XXXX, K  , M  ,GUCM,ALDT,CTSL,SHCA,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TTNP,TBMS,TDNS,        TTSN,TSNV,ENT
  //                  `----+----+----'        `----+----+----'
  ),

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     EQL , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAGE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,CAGQ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SHCP,CTLZ,ALTX,GUIC, V  , B  ,XXXX,     XXXX, N  , M  ,GUCM,ALDT,CTSL,SHCA,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TTNP,TBMS,TDNS,        TTSN,TSNV,ENT
  //                  `----+----+----'        `----+----+----'
  ),

  [_NAV] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,LCBR,RCBR,XXXX,               PGUP,HOME, UP ,END ,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,LBRC,RBRC,XXXX,               PGDN,LEFT,DOWN,RGHT,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX,XXXX,LPRN,RPRN,XXXX,XXXX,     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,BSPC,DEL ,        XXXX,XXXX,XXXX
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMSYM] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GRV, 1  , 2  , 3  , 4  , 5  ,                 6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     F11, F1 , F2 , F3 , F4 , F5 ,XXXX,      XXXX, F6 , F7 , F8 , F9 , F10, F12,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,XXXX,XXXX,        XXXX,SPC ,XXXX
  //                  `----+----+----'        `----+----+----'
  ),

  [_SYMNUM] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GRV, 1  , 2  , 3  , 4  , 5  ,                 6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     F11, F1 , F2 , F3 , F4 , F5 ,XXXX,      XXXX, F6 , F7 , F8 , F9 , F10, F12,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,XXXX,XXXX,        XXXX,XXXX,XXXX
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,XXXX,XXXX,        XXXX,XXXX,XXXX
  //                  `----+----+----'        `----+----+----'
  ),

  [_MOUSE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,XXXX,XXXX,        XXXX,XXXX,XXXX
  //                  `----+----+----'        `----+----+----'
  ),

  [_MEDIA] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,XXXX,XXXX,        XXXX,XXXX,XXXX
  //                  `----+----+----'        `----+----+----'
  ),

  [_X1] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     CADL, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     EQL , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,CAGQ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XSCP,CTLZ,ALTX,GUIC, V  , B  ,XXXX,     XXXX, N  , M  ,GUCM,ALDT,CTSL,XSCA,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       TTNP,TBMS,TDNS,        TTSN,TSNV,ENT
  //                  `----+----+----'        `----+----+----'
  ),

  [_X1RLAYER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,SLCK,SYSR,PSCR,INS ,PAUS,               MUTE,VOLD,VOLU,BLDN,BLUP,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TILD,GRV ,EQL ,LBRC,RBRC,               ASTR,PGUP, UP ,HOME,PLUS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM,PIPE,DLR ,LPRN,RPRN,               AMPR,LEFT,DOWN,RGHT,MINS,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , AT ,HASH,PERC,LCBR,RCBR,    ,         ,CIRC,PGDN ,UNDS,END ,BSLS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_CONFIG] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     REST,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,QWER,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX, X1 ,COLE,XXXX,XXXX,    ,         ,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,    ,XXXX,        XXXX,    ,XXXX
  //                  `----+----+----'        `----+----+----'
  )

    /* Template
  [_TEMPLATE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       XXXX,XXXX,XXXX,        XXXX,XXXX,XXXX
  //                  `----+----+----'        `----+----+----'
  )
  */
};


/* TAP DANCE */
void shift_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code (KC_CAPS);
  } else {
    register_code (KC_LSFT);
  }
}
void shift_caps_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code (KC_CAPS);
  } else {
    unregister_code (KC_LSFT);
  }
}
void shift_x1_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code (KC_LCTL);
  } else {
    register_code (KC_LSFT);
  }
}
void shift_x1_caps_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code (KC_LCTL);
  } else {
    unregister_code (KC_LSFT);
  }
}
void shift_ctrlalt_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    register_code (KC_LCTL);
    register_code (KC_LALT);
  } else if (state->count == 3) {
    register_code (KC_LALT);
  } else if (state->count == 2) {
    register_code (KC_LCTL);
  } else {
    register_code (KC_RSFT);
  }
}
void shift_ctlalt_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    unregister_code (KC_LALT);
    unregister_code (KC_LCTL);
  } else if (state->count == 3) {
    unregister_code (KC_LALT);
  } else if (state->count == 2) {
    unregister_code (KC_LCTL);
  } else {
    unregister_code (KC_RSFT);
  }
}
void shift_x1_ctrlalt_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    register_code (KC_LALT);
    register_code (KC_CAPS);
  } else if (state->count == 3) {
    register_code (KC_LALT);
  } else if (state->count == 2) {
    register_code (KC_CAPS);
  } else {
    register_code (KC_RSFT);
  }
}
void shift_x1_ctlalt_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    unregister_code (KC_CAPS);
    unregister_code (KC_LALT);
  } else if (state->count == 3) {
    unregister_code (KC_LALT);
  } else if (state->count == 2) {
    unregister_code (KC_CAPS);
  } else {
    unregister_code (KC_RSFT);
  }
}
void ctrlaltdel_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code (KC_DEL);
    unregister_code (KC_LALT);
    unregister_code (KC_LCTL);
  } else {
  }
}
void ctrlaltdel_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code (KC_LCTL);
    register_code (KC_LALT);
    register_code (KC_DEL);
  } else {
  }
}
qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_LGUIAPP] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_APP),
        [TD_SHIFTCAPS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shift_caps_down, shift_caps_up),
        [TD_SHIFTX1CAPS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shift_x1_caps_down, shift_x1_caps_up),
        [TD_SHIFTCLAT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shift_ctrlalt_down, shift_ctlalt_up),
        [TD_SHIFTX1CLAT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shift_x1_ctrlalt_down, shift_x1_ctlalt_up),
        [TD_CTRLALTDL] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, ctrlaltdel_down, ctrlaltdel_up)
};
/* END TAP DANCE */

bool x1Enabled = false;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
        x1Enabled = false;
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
        x1Enabled = false;
      }
      return false;
      break;
    case X1:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_X1);
        x1Enabled = true;
      }
      return false;
      break;
    case CONFIG:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CONFIG);
      }
      return false;
      break;
  }
  return true;
}

//void matrix_init_user(void) {
//  set_single_persistent_default_layer(_COLEMAK);
//}
/*
// LED breathing when a layer is locked
void matrix_scan_user(void) {
  // Only breath if layer is locked
  if (lockedBLLevel != 0 && (rlocked || llocked)){
    // counter to slow down the breathing
    if (counter >= breathPulse) {
      counter = 0;
      // iterate brightness up or down
      if (breathUp){
        backlight_increase();
      } else {
        backlight_decrease();
      }
      // figure out if we need to change directions
      currentBL = get_backlight_level();
      if (currentBL >= BACKLIGHT_LEVELS){
        breathUp = false;
        // make counter a big negative number to add some stall time
        counter = ((BACKLIGHT_LEVELS * breathPulseStall) * (-1));
      } else if (currentBL == 0){
        breathUp = true;
        // make counter a big negative number to add some stall time
        counter = ((BACKLIGHT_LEVELS * breathPulseStall) * (-1));
      }
      // make not that we need to change the brightness back to when we started the breathing
      resetBL = true;
    } else {
      counter++;
    }
  } else {
    // get the brightness back to the level it started at
    if (resetBL){
      int i = 0;
      // i is just there to make sure i don't get stuck in a loop if for some reason get_backlight_level isn't working as expected
      while (get_backlight_level() != lockedBLLevel && i <= BACKLIGHT_LEVELS ){
        backlight_step();
        i++;
      }
      resetBL = false;
    }
  }
}
*/
