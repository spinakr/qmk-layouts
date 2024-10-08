#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
    _COLEMAK,
    _RTHUMB,
    _LEFTTHUMB,    
    _FUNC
};


enum ferris_tap_dances {
  TD_Q_ESC
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
#define ALT_X LALT_T(KC_X)
#define CTL_Z LCTL_T(KC_Z)
#define SFT_A LSFT_T(KC_A)
#define CMD_D CMD_T(KC_D)


// Right-hand home row mods
#define NUM_E LT(_NUM,KC_E)
#define SYM_N LT(_LEFTSYM,KC_N)
#define ALT_E LALT_T(KC_E)
#define CTL_I RCTL_T(KC_I)
#define SFT_O RSFT_T(KC_O)
#define CMD_H CMD_T(KC_H)


#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT( /* QWERTY */
    KC_Q  , KC_W  ,  KC_F  ,   KC_P ,    KC_B,         KC_J ,   KC_L ,   KC_U ,    KC_Y,KC_MINS ,
    SFT_A , KC_R  , KC_S   ,   KC_T ,   KC_G ,         KC_M ,  KC_N , KC_E ,  KC_I ,  SFT_O , 
    CTL_Z  , ALT_X ,  KC_C ,   KC_D,    KC_V,         KC_K ,   KC_H , KC_COMM, KC_DOT ,KC_SLSH , 
              KC_LCMD,LT(_LEFTTHUMB,KC_SPACE),       LT(_RTHUMB, KC_BSPC),LT(_FUNC,KC_TAB)
  ),

  [_LEFTTHUMB] = LAYOUT( /* [> LOWER <] */
    KC_EXLM ,  KC_AT , KC_HASH, KC_DLR , KC_PERC,      KC_ESC,_______ ,_______ , _______ , _______,
    KC_CIRC ,  AE    , OE   ,    AA    , KC_PIPE,      _______,KC_LEFT,KC_DOWN, KC_UP  , KC_RGHT,      
    KC_TILDE,KC_AMPR,KC_PAST,KC_BSLS   , _______,      KC_GRV,KC_HOME,KC_PGDN, KC_PGUP, KC_END,
                                    KC_TRNS, KC_TRNS, ALT_TAB, LCMD(KC_GRV)  
  ),

  [_RTHUMB] = LAYOUT( /* [> RAISE <] */
    KC_PAST ,  KC_7  ,  KC_8  ,  KC_9  ,KC_PLUS ,           KC_RBRC ,KC_RPRN ,KC_RCBR ,KC_QUOT , KC_MINS, 
    KC_PSLS ,  KC_4  ,  KC_5  ,  KC_6  ,KC_MINS ,           KC_LBRC , KC_LPRN,KC_LCBR , KC_DQT , KC_UNDS, 
    KC_COMM ,  KC_1 ,   KC_2  ,  KC_3  ,KC_EQL  ,           KC_COLN , KC_SCLN, KC_LT  , KC_GT  , KC_QUES, 
                                    KC_0, KC_ENT,           KC_TRNS, KC_TRNS  
  ),
  [_FUNC] = LAYOUT( /* [> RAISE <] */
    QK_BOOT,  KC_F7  ,  KC_F8  ,  KC_F9  ,KC_F12 ,           RSG(KC_4) ,LCA(KC_H),LCA(KC_J) ,LCA(KC_K) , LCA(KC_L), 
    _______ ,  KC_F4  ,  KC_F5  ,  KC_F6  ,KC_F11 ,           _______ , C(KC_H),C(KC_J) ,C(KC_K) , C(KC_L), 
    _______ ,  KC_F1 ,   KC_F2  ,  KC_F3  ,KC_F10  ,           _______ , _______, _______  , _______  ,_______, 
                                    OSM(MOD_MEH), LCMD(KC_SPACE), _______, _______  
  )
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LCMD);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LCMD);
      is_alt_tab_active = false;
    }
  }
}