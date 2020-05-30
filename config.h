// configuration for jgjin's crkbd keymap

#pragma once

// left side is master
#define MASTER_LEFT

// use OLED screens
#define SSD1306OLED

// def for split keyboard?
#define USE_SERIAL_PD2

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
#define PERMISSIVE_HOLD

// threshold (in ms) to interpret tap rather than hold
#define TAPPING_TERM 200

// IBus unicode support
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
