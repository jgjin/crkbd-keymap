#include QMK_KEYBOARD_H

#include "process_unicode.h"

extern uint8_t is_master;

// layer names for readability
#define _QWERTY 0
#define _EMOJI 1
#define _RAISE 2

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EMOJI,
    RAISE,
    SIGN,
    QUOTE,
    DELTONGUE,
    DELGRIN,
    DELBANANA,
    LEFTPRN,
    LEFTCBR,
    LEFTBRC,
    LEFTABK,
    RGHTABK,
    RGHTBRC,
    RGHTCBR,
    RGHTPRN
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
    [SUNGLASSES]   = 0x1F60E,
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
  //,------------------------------------------------------------------------.                    ,---------------------------------------------------------------------.
               KC_TAB,    KC_Q,    KC_W,    KC_E,               KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,         KC_BSPC, \
  //|----------------+--------+--------+--------+-------------------+--------|                    |----------------+--------+--------+--------+--------+----------------|
       LCMD_T(KC_ESC),    KC_A,    KC_S,    KC_D,               KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,           QUOTE, \
  //|----------------+--------+--------+--------+-------------------+--------|                    |----------------+--------+--------+--------+--------+----------------|
      LALT_T(KC_LEFT),    KC_Z,    KC_X,    KC_C,               KC_V,    KC_B,                                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RCTL_T(KC_RGHT), \
  //|----------------+--------+--------+--------+-------------------+--------+--------|  |--------+----------------+--------+--------+--------+--------+----------------|
                                                  LT(_EMOJI, KC_ENT),  KC_SPC, XXXXXXX,    XXXXXXX, RSFT_T(KC_BSPC),   RAISE \
                                              //`-------------------------------------'  `----------------------------------'
    ),

    [_EMOJI] = LAYOUT( \
  //,--------------------------------------------------------------------------------.  ,-----------------------------------------------------------------------.
        KC_F2, X(QUESTIONING),     X(WIZARD),          X(EGG), X(RELIEVED), DELTONGUE,      X(YEN), X(UPSIDE_DOWN),     X(IMP), X(OPEN_MOUTH), X(PIZZA), KC_BSPC, \
  //|--------+---------------+--------------+----------------+------------+----------|  |---------+---------------+-----------+--------------+---------+--------|
        KC_F3,      X(ANGERY), X(SUNGLASSES), X(DISAPPOINTED),     X(FIRE),   DELGRIN,    X(HEART),    X(JOYSTICK),   X(KISSY),   X(LAUGHING),  X(POOP),  KC_F11, \
  //|--------+---------------+--------------+----------------+------------+----------|  |---------+---------------+-----------+--------------+---------+--------|
        KC_F4,         X(ZZZ),     X(X_MARK),    X(COPYRIGHT),    X(VOMIT), DELBANANA,     X(NOSE),      X(MONKEY), X(BALLOON), X(CHECK_MARK), X(SWORD),  KC_F12, \
  //|--------+---------------+--------------+----------------+------------+----------|  |---------+---------------+-----------+--------------+---------+--------|
                                                      XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,         KC_DEL,    XXXXXXX \
                                          //`----------------------------------------'  `-------------------------------------'
    ),

    [_RAISE] = LAYOUT( \
  //,-------------------------------------------------------------------.                    ,-----------------------------------------------------------.
              KC_TAB, KC_EXLM,   KC_AT, KC_HASH,         KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS,  KC_EQL,       KC_BSPC, \
  //|---------------+--------+--------+--------+---------------+--------|                    |--------+--------+--------+--------+--------+--------------|
      LCMD_T(KC_ESC),    KC_1,    KC_2,    KC_3,           KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          SIGN, \
  //|---------------+--------+--------+--------+---------------+--------|                    |--------+--------+--------+--------+--------+--------------|
       LALT_T(KC_F3),  KC_GRV, LEFTPRN, LEFTCBR,        LEFTBRC, LEFTABK,                      RGHTABK, RGHTBRC, RGHTCBR, RGHTPRN, KC_BSLS, RCTL_T(KC_F4), \
  //|---------------+--------+--------+--------+---------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------------|
                                                 LSFT_T(KC_ENT),  KC_SPC, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                             //`---------------------------------'  `--------------------------'
    )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
#ifdef SSD1306OLED
    iota_gfx_init(!has_usb());   // turns on the display
#endif
}

#ifdef SSD1306OLED

const char *read_layer_state(void);
const char *read_logo(void);

void matrix_scan_user(void) {
    iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
        matrix_write_ln(matrix, "\n\n  podex perfectus es");
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
    const uint8_t mod_state = get_mods();
    uint16_t custom_keycode;
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
    case SIGN: ;
        custom_keycode = KC_MINUS;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_PLUS;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    case QUOTE: ;
        if (mod_state & MOD_MASK_SHIFT) {
            if (record->event.pressed) {
                clear_mods();
                tap_code(KC_QUOTE);
                set_mods(mod_state);
            }
        } else {
            if (record->event.pressed) {
                register_code16(KC_DQUO);
            } else {
                unregister_code16(KC_DQUO);
            }
        }
        return false;
    case DELTONGUE:
        if (record->event.pressed) {
            tap_code(KC_BSPC);
            send_unicode_hex_string("1F445");
        }
        return false;
    case DELGRIN:
        if (record->event.pressed) {
            tap_code(KC_BSPC);
            send_unicode_hex_string("1F600");
        }
        return false;
    case DELBANANA:
        if (record->event.pressed) {
            tap_code(KC_BSPC);
            send_unicode_hex_string("1F34C");
        }
        return false;
    case LEFTPRN: ;
        custom_keycode = KC_LPRN;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_HOME;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    case LEFTCBR: ;
        custom_keycode = KC_LCBR;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_PGDOWN;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    case LEFTBRC: ;
        custom_keycode = KC_LBRC;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_PGUP;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    case LEFTABK: ;
        custom_keycode = KC_LABK;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_END;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    case RGHTABK: ;
        custom_keycode = KC_LEFT;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_RABK;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    case RGHTBRC: ;
        if (mod_state & MOD_MASK_SHIFT) {
            if (record->event.pressed) {
                clear_mods();
                tap_code(KC_RBRC);
                set_mods(mod_state);
            }
        } else {
            if (record->event.pressed) {
                register_code16(KC_DOWN);
            } else {
                unregister_code16(KC_DOWN);
            }
        }
        return false;
    case RGHTCBR: ;
        custom_keycode = KC_UP;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_RCBR;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    case RGHTPRN: ;
        custom_keycode = KC_RGHT;
        if (mod_state & MOD_MASK_SHIFT) {
            custom_keycode = KC_RPRN;
        }

        if (record->event.pressed) {
            register_code16(custom_keycode);
        } else {
            unregister_code16(custom_keycode);
        }
        return false;
    }
    return true;
}
