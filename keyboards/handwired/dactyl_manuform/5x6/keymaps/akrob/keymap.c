#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _QWERTY 1
#define _NAV 2
#define _NUMSYM 3
#define _LLAYER 4
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

#define T_NSTB LT(_NUMSYM, KC_TAB)
#define T_RLET LT(_NAV, KC_ENT)
#define T_LLNP LT(_LLAYER, KC_DEL)


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
     KC_EQL , KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_BSLS,
     CAG_ESC, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                         KC_H  , KC_N  , KC_E  , KC_I  , KC_O  ,CAG_QUO,
     KC_LSFT, CTL_Z ,  KC_X ,  KC_C ,  KC_V,   KC_B ,                         KC_K  , KC_M  ,KC_COMM, KC_DOT,CTL_SLSH,KC_RSFT,
                     KC_LALT,KC_LGUI,                                                        KC_RGUI ,KC_RALT,
                                      T_NSTB,KC_BSPC ,                       KC_SPC ,T_RLET ,
                                      XXXXXXX,T_LLNP ,                       MO(_RLAYER),XXXXXXX,
                                      XXXXXXX,RESET  ,                       XXXXXXX,XXXXXXX
  ),

  [_QWERTY] = LAYOUT_5x6(
     XXXXXXX, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_BSPC,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , KC_DEL,
     KC_CTEC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN, KC_ENT,
     KC_LSFT , CTL_Z ,  ALT_X,  GUI_C,  KC_V,   KC_B ,                         KC_N  , KC_M  , GUI_COMM, ALT_DOT,CTL_SLSH,KC_RSFT,
                      XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
                                      T_NSTB,KC_BSPC ,                       KC_SPC ,T_RLET ,
                                      XXXXXXX,T_LLNP ,                       MO(_RLAYER),XXXXXXX,
                                      XXXXXXX,RESET  ,                       XXXXXXX,XXXXXXX
  ),
  [_RLAYER] = LAYOUT_5x6(
     _______,KC_SLCK,KC_SYSR,KC_PSCR,KC_INS ,KC_PAUS,                        KC_MUTE,KC_VOLD,KC_VOLU,_______,_______,_______,
     _______,KC_TILD,KC_GRV ,KC_EQL ,KC_LBRC,KC_RBRC,                        KC_ASTR,KC_HOME,KC_UP  ,KC_END ,KC_PLUS,_______,
     _______,KC_EXLM,KC_PIPE,KC_DLR ,KC_LPRN,KC_RPRN,                        KC_AMPR,KC_LEFT,KC_DOWN,KC_RGHT,KC_MINS,KC_QUOT,
     _______,KC_AT  ,KC_HASH,KC_PERC,KC_LCBR,KC_RCBR,                        KC_CIRC,KC_PGUP ,KC_UNDS,KC_PGDN,KC_BSLS,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
  ),
  [_LLAYER] = LAYOUT_5x6(
     
     _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_UP  ,KC_F5  ,XXXXXXX,                        KC_ASTR,KC_7   ,KC_8   ,KC_9   ,KC_PLUS,_______,
     XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,KC_ENT ,                        KC_SLSH,KC_4   ,KC_5   ,KC_6   ,KC_MINS,_______,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_BSPC,KC_SINS,KC_SPC ,                        KC_EQL ,KC_1   ,KC_2   ,KC_3   ,KC_DOT ,_______,
                                             _______,KC_F11 ,            KC_F12 ,_______,
                                             _______,_______,            KC_0   ,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
  ),
  [_NAV] = LAYOUT_5x6(
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_LCBR,KC_RCBR,XXXXXXX,                        KC_PGUP,KC_HOME, KC_UP ,KC_END ,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_LBRC,KC_RBRC,XXXXXXX,                        KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,XXXXXXX,
     XXXXXXX,XXXXXXX,XXXXXXX,KC_LPRN,KC_RPRN,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
  ),
  [_NUMSYM] = LAYOUT_5x6(
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,
     KC_GRV,KC_1  ,KC_2  ,KC_3  ,KC_4  ,KC_5  ,                        KC_6  ,KC_7  ,KC_8  ,KC_9  ,KC_0 ,KC_MINS,
     KC_F11,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
  )
  /*
  Blank layout for more layers
  [_NEW_LAYOUT] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
  ),*/
};

