#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
    _COLEMAK,
    _LEFTSYM,
    _RIGHTSYM,    
    _NAV,
    _NUM,
    _ALW
};


//aliases for clarity in layering
#define SftEnt SFT_T(KC_ENT)   // Shift when held, Enter when tapped
#define BSCTL  LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped
#define CTAB   LCTL(KC_TAB)
#define ATAB   LALT(KC_TAB)
#define CMDTAB   LGUI(KC_TAB)
#define SS LSG(KC_4)

//aliases for Navigation layer
#define WDBSPC LALT(KC_BSPC)  // delete whole word
#define C_CL   LCTL(KC_LEFT) // move cursor one word back
#define C_CR   LCTL(KC_RGHT) // move cursor one word forward
#define CUT   LCMD(KC_X)
#define COPY   LCMD(KC_C)
#define PASTE   LCMD(KC_V)
#define UNDO   LCMD(KC_Z)
#define REDO   LSG(KC_Z)
#define CMDW   LCMD(KC_W)
#define CMDT   LCMD(KC_T)
#define CMDA   LCMD(KC_A)
#define CMDS   LCMD(KC_S)
#define CMDC   LCMD(KC_C)
#define CMDV   LCMD(KC_V)
#define CMDZ   LCMD(KC_Z)
#define CMDF   LCMD(KC_F)


#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)

//Norwegian letters, EurKeys layout
#define AA   LALT(KC_W)
#define AE   LALT(KC_Q)
#define OE   LALT(KC_L)

#define SftSpc LSFT_T(KC_SPC)
// Left-hand home row mods
#define SYM_S LT(_RIGHTSYM,KC_S)
#define NAV_T LT(_NAV,KC_T)
#define ALT_C LALT_T(KC_C)
#define CTL_X LCTL_T(KC_X)
#define SFT_A LSFT_T(KC_A)

// Right-hand home row mods
#define NUM_E LT(_NUM,KC_E)
#define SYM_N LT(_LEFTSYM,KC_N)
#define ALT_E LALT_T(KC_E)
#define CTL_I RCTL_T(KC_I)
#define SFT_O RSFT_T(KC_O)


enum ferris_tap_dances {
  TD_Q_ESC
};

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT( /* QWERTY */
    KC_Q  , KC_W  ,  KC_F  ,   KC_P,    KC_B,         KC_J ,   KC_L ,   KC_U ,    KC_Y,KC_MINS ,
    SFT_A , KC_R  , SYM_S ,   NAV_T,   KC_G,         KC_M ,  SYM_N , NUM_E ,  KC_I ,  SFT_O , 
    KC_Z  , CTL_X ,  ALT_C ,   KC_D,    KC_V,         KC_K ,   KC_H , KC_COMM, KC_DOT ,KC_SLSH , 
                         KC_MEH, SftSpc,         LT(_ALW, KC_BSPC) ,_______ 
  ),

  [_NAV] = LAYOUT( /* [> LOWER <] */
    _______,_______,_______,_______,  _______,      _______,C(KC_H)   ,C(KC_J)   , C(KC_K)   , C(KC_L),
    _______,_______,_______,_______,  _______,      _______,KC_LEFT,KC_DOWN, KC_UP  , KC_RGHT,
    _______,_______,_______,_______,  _______,      _______,KC_HOME,KC_PGDN, KC_PGUP, KC_END,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  
  ),

  [_RIGHTSYM] = LAYOUT( /* [> RAISE <] */
    QK_BOOT,_______,_______,_______,  _______,           KC_RBRC ,KC_RPRN ,KC_RCBR ,KC_QUOT , KC_MINS, 
    _______,_______,_______,_______,  _______,           KC_LBRC , KC_LPRN,KC_LCBR , KC_DQT , KC_UNDS, 
    _______,_______,_______,_______,  _______,           KC_COLN , KC_SCLN, KC_LT  , KC_GT  , KC_QUES, 
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  
  ),
  [_LEFTSYM] = LAYOUT( /* [> RAISE <] */
    KC_EXLM ,  KC_AT , KC_HASH, KC_DLR , KC_PERC,      _______,_______,_______,_______,  _______,
    KC_CIRC ,KC_AMPR ,KC_PAST ,KC_BSLS ,KC_PIPE ,      _______,_______,_______,_______,  _______,
    KC_TILDE,_______,_______,_______   , KC_GRV     ,      _______,_______,_______,_______,  _______,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  
  ),

  [_NUM] = LAYOUT( /* [> RAISE <] */
    KC_PAST ,  KC_7  ,  KC_8  ,  KC_9  ,KC_PLUS ,     _______,_______,_______,_______,  _______,
    KC_PSLS ,  KC_4  ,  KC_5  ,  KC_6  ,KC_MINS ,      _______,_______,_______,_______,  _______,
    KC_0 ,  KC_1 ,   KC_2  ,  KC_3  ,KC_EQL  ,     _______,_______,_______,_______,  _______,
                                    KC_ENT, KC_COMM,            KC_TRNS, KC_TRNS  
  ),
  [_ALW] = LAYOUT( /* [> ADJUST <] */
    _______,_______,KC_COLN,KC_ESC ,_______,            _______,_______,_______,_______,_______,
    AE     ,  OE   ,  AA   ,KC_ENT ,_______,            _______,OSM(MOD_LGUI) ,_______,_______,_______,
    _______,_______,_______,_______,_______,           _______,_______,_______,_______,_______,
                                    KC_GRV,KC_TAB,_______,_______
  )
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
