#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _QWERTY 1
#define _NAV 2
#define _NUMSYM 3
#define _NUMPAD 4
#define _RLAYER 5
#define _DUAL 6  
#define _CONFIG 7


#define ALT_DOT     ALT_T(KC_DOT)
#define ALT_X       ALT_T(KC_X)

#define CTL_SLSH    CTL_T(KC_SLSH)
#define CTL_Z       CTL_T(KC_Z)

#define GUI_C       GUI_T(KC_C)
#define GUI_COMM    GUI_T(KC_COMM)

#define HPR_ESC     ALL_T(KC_ESC)
#define HPR_QUO     ALL_T(KC_QUOT)

#define CAG_ESC     LCAG_T(KC_ESC)
#define CAG_QUO     RCAG_T(KC_QUOT)

#define GUI_ESC     GUI_T(KC_ESC)
#define GUI_QUO     GUI_T(KC_QUOT)

#define HPR_LATCH  ALL_T(KC_NO)

// Toggle to VIM when left space button is held, emit space keycode when left space is tapped
#define TGL_DEV LT(_DEV, KC_SPC)
// Toggle to MEDIA layer
#define TGL_MEDIA LT(_MEDIA, KC_SCLN)
// Toggle to the mouse layer when the right space button is held and emit enter when right space is tapped
#define TGL_MOUSE LT(_MOUSE, KC_ENT)
#define TGL_NAV LT(_RLAYER, KC_O)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define T_NSDEL LT(_NUMSYM, KC_DEL)
#define T_NPTAB LT(_NUMPAD, KC_TAB)


/* Custom Shortened Keys (4 digits so they fit in my grid) */
#define KC_MCTB LCTL(KC_TAB)
#define KC_MCST LCTL(LSFT(KC_TAB))
#define KC_CTEC CTL_T(KC_ESC)
#define KC_SINS LSFT(KC_INS)
#define KC_SYSR KC_SYSREQ
#define KC_REST RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_5x6(
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_BSLS,
     GUI_ESC, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                         KC_H  , KC_N  , KC_E  , KC_I  , KC_O  ,GUI_QUO,
     KC_LSFT, CTL_Z ,  KC_X ,  KC_C ,  KC_V,   KC_B ,                         KC_K  , KC_M  ,KC_COMM, KC_DOT,CTL_SLSH,KC_RSFT,
                     KC_LALT,KC_LGUI,                                                        KC_RGUI ,KC_RALT,
                                             T_NSDEL,KC_BSPC,        KC_SPC ,MO(_NAV),
                                             XXXXXXX,T_NPTAB,        KC_ENT ,DF(_QWERTY),
                                             XXXXXXX,RESET  ,        XXXXXXX,RESET
  ),

  [_QWERTY] = LAYOUT_5x6(
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
     GUI_ESC, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,GUI_QUO,
     KC_LSFT, CTL_Z , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM, KC_DOT,CTL_SLSH,KC_RSFT,
                     KC_LALT,KC_LGUI,                                                        KC_RGUI ,KC_RALT,
                                             T_NSDEL,KC_BSPC,        KC_SPC ,MO(_NAV),
                                             XXXXXXX,T_NPTAB,        KC_ENT ,DF(_COLEMAK),
                                             XXXXXXX,RESET  ,        XXXXXXX,RESET
  ),
  [_NUMPAD] = LAYOUT_5x6(
     
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_UP  ,KC_F5  ,XXXXXXX,                        KC_ASTR,KC_7   ,KC_8   ,KC_9   ,KC_PLUS,_______,
     XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT ,                        KC_SLSH,KC_4   ,KC_5   ,KC_6   ,KC_MINS,_______,
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_SINS,KC_SPC ,                        KC_EQL ,KC_1   ,KC_2   ,KC_3   ,KC_DOT ,_______,
                     _______,_______,                                                        _______,_______,
                                             _______,_______,        KC_0   ,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),
  [_NAV] = LAYOUT_5x6(
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_LBRC,KC_RBRC,XXXXXXX,                        KC_PGUP,KC_HOME, KC_UP ,KC_END ,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_LPRN,KC_RPRN,XXXXXXX,                        KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,XXXXXXX,
     _______,XXXXXXX,XXXXXXX,KC_LCBR,KC_RCBR,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
                     _______,_______,                                                        _______,_______,
                                             KC_DEL ,_______,        _______,_______,
                                             _______,KC_ENT ,        _______,_______,
                                             _______,_______,        _______,_______
  ),
  [_NUMSYM] = LAYOUT_5x6(
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     KC_F11 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F12 ,
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
     KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,
                     _______,_______,                                                        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  )
  /*
  Blank layout for more layers
  [_NEW_LAYOUT] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                     _______,_______,                                                        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),*/
};

