#include QMK_KEYBOARD_H

extern uint8_t is_master;

// layer names for readability
#define _QWERTY 0
#define _EMOJI 1
#define _RAISE 2

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EMOJI,
    RAISE
};

// tap dance declarations
enum {
    DELETE = 0,
    SIGN   = 1,
    QUOTE  = 2
};

void td_sign_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_MINUS);
    } else {
        register_code(KC_RSHIFT);
        register_code(KC_EQUAL);
    }
}

void td_sign_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_MINUS);
    } else {
        unregister_code(KC_RSHIFT);
        unregister_code(KC_EQUAL);
    }
}

void td_quote_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOTE);
    } else {
        register_code(KC_RSHIFT);
        register_code(KC_QUOTE);
    }
}

void td_quote_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOTE);
    } else {
        unregister_code(KC_RSHIFT);
        unregister_code(KC_QUOTE);
    }
}

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [DELETE] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_DEL),
    [SIGN]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_sign_finished, td_sign_reset),
    [QUOTE]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_quote_finished, td_quote_reset)
};

enum unicode_names {
    ANGERY,
    BANANA,
    COPYRIGHT,
    DISAPPOINTED,
    EGG,
    FIRE,
    GRIN,
    HEART,
    IMP,
    JOYSTICK,
    KISSY,
    LAUGHING,
    MONKEY,
    NOSE,
    OPEN_MOUTH,
    PIZZA,
    QUESTIONING,
    RELIEVED,
    SUNGLASSES,
    TONGUE,
    UPSIDE_DOWN,
    VOMIT,
    WIZARD,
    X_MARK,
    YEN,
    ZZZ,
    POOP,
    BALLOON,
    CHECK_MARK,
    SWORD
};

const uint32_t PROGMEM unicode_map[] = {
    [ANGERY]       = 0x1F620,
    [BANANA]       = 0x1F34C,
    [COPYRIGHT]    = 0xA9,
    [DISAPPOINTED] = 0x1F61E,
    [EGG]          = 0x1F95A,
    [FIRE]         = 0x1F525,
    [GRIN]         = 0x1F600,
    [HEART]        = 0x1F496,
    [IMP]          = 0x1F608,
    [JOYSTICK]     = 0x1F579,
    [KISSY]        = 0x1F618,
    [LAUGHING]     = 0x1F923,
    [MONKEY]       = 0x1F648,
    [NOSE]         = 0x1F443,
    [OPEN_MOUTH]   = 0x1F62E,
    [PIZZA]        = 0x1F355,
    [QUESTIONING]  = 0x1F914,
    [RELIEVED]     = 0x1F60C,
    [SUNGLASSES]   = 0x1F60C,
    [TONGUE]       = 0x1F445,
    [UPSIDE_DOWN]  = 0x1F643,
    [VOMIT]        = 0x1F92E,
    [WIZARD]       = 0x1F9D9,
    [X_MARK]       = 0x274C,
    [YEN]          = 0x1F4B4,
    [ZZZ]          = 0x1F634,
    [POOP]         = 0x1F4A9,
    [BALLOON]      = 0x1F388,
    [CHECK_MARK]   = 0x2705,
    [SWORD]        = 0x2694
};


enum macro_keycodes {
    KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
  //,------------------------------------------------------------.                    ,------------------------------------------------------------------.
              KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,           KC_U,    KC_I,    KC_O,   KC_P,     TD(DELETE), \
  //|---------------+--------+--------+--------+--------+--------|                    |--------+---------------+--------+--------+--------+--------------|
      LCMD_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,           KC_J,    KC_K,    KC_L, KC_SCLN,     TD(QUOTE), \
  //|---------------+--------+--------+--------+--------+--------|                    |--------+---------------+--------+--------+--------+--------------|
       LALT_T(KC_F3),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,           KC_M, KC_COMM,  KC_DOT, KC_SLSH, RCTL_T(KC_F4), \
  //|---------------+--------+--------+--------+--------+--------+--------|  |--------+--------+---------------+--------+--------+--------+--------------|
                                                  KC_SPC,   EMOJI, XXXXXXX,    XXXXXXX,   RAISE, RSFT_T(KC_ENT) \
                                             //`--------------------------'  `---------------------------------'
    ),

    [_EMOJI] = LAYOUT( \
  //,---------------------------------------------------------------------------------------.  ,---------------------------------------------------------------------------------.
              KC_TAB, X(QUESTIONING),     X(WIZARD),          X(EGG), X(RELIEVED), X(TONGUE),      X(YEN), X(UPSIDE_DOWN),         X(IMP), X(OPEN_MOUTH), X(PIZZA),    TD(DELETE), \
  //|---------------+---------------+--------------+----------------+------------+----------|  |---------+---------------+---------------+--------------+---------+--------------|
      LCMD_T(KC_ESC),      X(ANGERY), X(SUNGLASSES), X(DISAPPOINTED),     X(FIRE),   X(GRIN),    X(HEART),    X(JOYSTICK),       X(KISSY),   X(LAUGHING),  X(POOP),     TD(QUOTE), \
  //|---------------+---------------+--------------+----------------+------------+----------|  |---------+---------------+---------------+--------------+---------+--------------|
       LALT_T(KC_F3),         X(ZZZ),     X(X_MARK),    X(COPYRIGHT),    X(VOMIT), X(BANANA),     X(NOSE),      X(MONKEY),     X(BALLOON), X(CHECK_MARK), X(SWORD), RCTL_T(KC_F4), \
  //|---------------+---------------+--------------+----------------+------------+----------|  |---------+---------------+---------------+--------------+---------+--------------|
                                                              KC_SPC,       EMOJI,   XXXXXXX,     XXXXXXX,          RAISE, RSFT_T(KC_ENT) \
                                                 //`----------------------------------------'  `-----------------------------------------'
    ),

    [_RAISE] = LAYOUT( \
  //,------------------------------------------------------------.                    ,------------------------------------------------------------------.
              KC_TAB, KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, KC_UNDS,                       KC_EQL,        KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN,    TD(DELETE), \
  //|---------------+--------+--------+--------+--------+--------|                    |--------+---------------+--------+--------+--------+--------------|
      LCMD_T(KC_ESC),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,           KC_7,    KC_8,    KC_9,    KC_0,      TD(SIGN), \
  //|---------------+--------+--------+--------+--------+--------|                    |--------+---------------+--------+--------+--------+--------------|
       LALT_T(KC_F3),  KC_GRV, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,                      KC_LEFT,        KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS, RCTL_T(KC_F4), \
  //|---------------+--------+--------+--------+--------+--------+--------|  |--------+--------+---------------+--------+--------+--------+--------------|
                                                  KC_SPC,   EMOJI, XXXXXXX,    XXXXXXX,   RAISE, RSFT_T(KC_ENT) \
                                             //`--------------------------'  `---------------------------------'
    )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

#ifdef SSD1306OLED

const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void matrix_scan_user(void) {
    iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
        matrix_write_ln(matrix, read_layer_state());
        matrix_write_ln(matrix, read_keylog());
    } else {
        matrix_write(matrix, read_logo());
    }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
}

#endif // SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef SSD1306OLED
        set_keylog(keycode, record);
#endif
    }

    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
        }
        return false;
    case EMOJI:
        if (record->event.pressed) {
            layer_on(_EMOJI);
        } else {
            layer_off(_EMOJI);
        }
        return false;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
        } else {
            layer_off(_RAISE);
        }
        return false;
    }
    return true;
}
