#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _X1 2
#define _X1RLAYER 3
#define _RLAYER 4 
#define _LLAYER 5
#define _DUAL 6
#define _CONFIG 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,        // qwerty base layer
  COLEMAK,                    // colemak base layer
  X1,                         // x1 carbon base layer
  X1RLAYER,                   // x1 carbon right layer
  RLAYER,                     // right layer
  LLAYER,                     // left layer
  RLOCK,                      // right layer LOCK
  LLOCK,                      // left layer LOCK
  DUAL,                       // right and left combo layer
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
#define KC_LLAY LLAYER
#define KC_RLAY RLAYER
#define KC_RLOK RLOCK
#define KC_LLOK LLOCK
#define KC_QWER QWERTY
#define KC_COLE COLEMAK
#define KC_X1   X1
#define KC_DUAL DUAL
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

/* Tap Dance */
#define KC_LGUA TD(TD_LGUIAPP)
#define KC_SHCP TD(TD_SHIFTCAPS)
#define KC_XSCP TD(TD_SHIFTX1CAPS)
#define KC_CADL TD(TD_CTRLALTDL)
#define KC_SHCA TD(TD_SHIFTCLAT)
#define KC_XSCA TD(TD_SHIFTX1CLAT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     CADL, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTEC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SHCP, Z  , X  , C  , V  , B  ,LLOK,     RLOK, N  , M  ,COMM,DOT ,SLSH,SHCA,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LLAY,TAB ,        SPC ,RLAY,LGUA
  //                  `----+----+----'        `----+----+----'
  ),

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     CADL, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , G  ,                J  , L  , U  , Y  ,SCLN,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTEC, A  , R  , S  , T  , D  ,                H  , N  , E  , I  , O  ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SHCP, Z  , X  , C  , V  , B  ,LLOK,     RLOK, K  , M  ,COMM,DOT ,SLSH,SHCA,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LLAY,TAB ,        SPC ,RLAY,LGUA
  //                  `----+----+----'        `----+----+----'
  ),

  [_X1] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     CADL, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     XSCP, Z  , X  , C  , V  , B  ,LLOK,     RLOK, N  , M  ,COMM,DOT ,SLSH,XSCA,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LLAY,TAB ,        SPC ,RLAY,LGUA
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

  [_RLAYER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,SLCK,SYSR,PSCR,INS ,PAUS,               MUTE,VOLD,VOLU,BLDN,BLUP,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TILD,GRV ,EQL ,LBRC,RBRC,               ASTR,HOME, UP ,PGUP,PLUS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM,PIPE,DLR ,LPRN,RPRN,               AMPR,LEFT,DOWN,RGHT,MINS,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , AT ,HASH,PERC,LCBR,RCBR,    ,         ,CIRC,END ,UNDS,PGDN,BSLS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_LLAYER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,XXXX,XXXX, UP , F5 ,XXXX,               ASTR, 7  , 8  , 9  ,PLUS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,XXXX,MCST,DOWN,MCTB,ENT ,               SLSH, 4  , 5  , 6  ,MINS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,XXXX,XXXX,BSPC,SINS,SPC ,F11 ,     F12 ,EQL , 1  , 2  , 3  ,DOT ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,         0  ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_DUAL] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,XXXX,XXXX,XXXX,XXXX,XXXX,               XXXX,XXXX,XXXX,XXXX,XXXX,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,LGU1,LGU2,LGU3,LGU4,LGU5,CONF,     BTN2,LGU6,LGU7,LGU8,LGU9,LGU0,    ,
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
  ),
};


/* VARIABLES */
// Configurable Variables for layer toggled light
int layerBLStep = 20;         // change how much the brightness changes when holding layer key
int breathPulse = 5;          // timing of the breathing
int breathPulseStall = 3;     // time to pause at top and bottom of breath cycle
int blSteps = 6;              // blSteps + 1 is the amount of brightness settings when manually adjusting

// Variables needed for layer locked breathing and layer toggling lighting to work
int counter = 0;
bool breathUp = true;
bool resetBL = false;
bool rlocked = false;
bool llocked = false;
bool configOn = false;
int lockedBLLevel;
int momentaryLBLLevel;
int momentaryRBLLevel;
int currentBL;
bool x1Enabled = false;
/* END VARIABLES */

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



void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
        configOn = false;
        x1Enabled = false;
        if (momentaryRBLLevel != 0 || momentaryLBLLevel != 0){
          backlight_toggle();
        }
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
        configOn = false;
        x1Enabled = false;
        if (momentaryRBLLevel != 0 || momentaryLBLLevel != 0){
          backlight_toggle();
        }
      }
      return false;
      break;
    case X1:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_X1);
        configOn = false;
        x1Enabled = true;
        if (momentaryRBLLevel != 0 || momentaryLBLLevel != 0){
          backlight_toggle();
        }
      }
      return false;
      break;
    case CONFIG:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CONFIG);
        configOn = true;
        if (momentaryRBLLevel != 0 || momentaryLBLLevel != 0){
          backlight_toggle();
        }
      }
      return false;
      break;
    case RLAYER:
      if (record->event.pressed) {
        if (x1Enabled){
          layer_on(_X1RLAYER);
          update_tri_layer(_X1RLAYER, _LLAYER, _DUAL);
        } else {
          layer_on(_RLAYER);
          update_tri_layer(_RLAYER, _LLAYER, _DUAL);
        }
        momentaryRBLLevel = get_backlight_level();
        if (momentaryRBLLevel != 0 || momentaryLBLLevel != 0){
          for (int i = 0; i < layerBLStep ; i++){
            backlight_increase();
          }
        }
      } else {
        unregister_code(KC_LGUI);
        if (x1Enabled){
          layer_off(_X1RLAYER);
          update_tri_layer(_X1RLAYER, _LLAYER, _DUAL);
        } else {
          layer_off(_RLAYER);
          update_tri_layer(_RLAYER, _LLAYER, _DUAL);
        }
        if ( llocked == false && configOn == false ) {
          for (int i = 0; i < layerBLStep ; i++){
            backlight_decrease();
          }
        } else {
        }
        rlocked = false;
      }
      return false;
      break;
    case LLAYER:
      if (record->event.pressed) {
        layer_on(_LLAYER);
        if (x1Enabled){
          update_tri_layer(_X1RLAYER, _LLAYER, _DUAL);
        } else {
          update_tri_layer(_RLAYER, _LLAYER, _DUAL);
        }
        momentaryLBLLevel = get_backlight_level();
        if (momentaryRBLLevel != 0 || momentaryLBLLevel != 0){
          for (int i = 0; i < layerBLStep ; i++){
            backlight_increase();
          }
        }
      } else {
        layer_off(_LLAYER);
        if (x1Enabled){
          update_tri_layer(_X1RLAYER, _LLAYER, _DUAL);
        } else {
          update_tri_layer(_RLAYER, _LLAYER, _DUAL);
        }
        if ( rlocked == false && configOn == false ) {
          for (int i = 0; i < layerBLStep ; i++){
            backlight_decrease();
          }
        } else {
        }
        llocked = false;
      }
      return false;
      break;
    case RLOCK:
      if (record->event.pressed) {
        if (x1Enabled){
          layer_on(_X1RLAYER);
        } else {
          layer_on(_RLAYER);
        }
        /* add logic to toggle backlight change when on a layer */
        if (rlocked == false && llocked == false){
          lockedBLLevel = get_backlight_level();
        }
        rlocked = true;
      } else {
      }
      return false;
      break;
    case LLOCK:
      if (record->event.pressed) {
        layer_on(_LLAYER);
        /* add logic to toggle backlight change when on a layer */
        if (rlocked == false && llocked == false){
          lockedBLLevel = get_backlight_level();
        }
        llocked = true;
      } else {
      }
      return false;
      break;
    case LEDUP:
      if (record->event.pressed) {
        for (int i = 0; i < (BACKLIGHT_LEVELS / blSteps ) ; i++ ){
          backlight_increase();
        }
      } else {
      }
      return false;
      break;
    case LEDDOWN:
      if (record->event.pressed) {
        for (int i = 0; i < (BACKLIGHT_LEVELS / blSteps ) ; i++ ){
          backlight_decrease();
        }
      } else {
      }
      return false;
      break;
  }
  return true;
}


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
