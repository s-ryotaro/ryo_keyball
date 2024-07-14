//https://yakinikunotare.boo.jp/orebase2/keyboard/diy_keyboard/qmk/tap_dance/start
//https://docs.qmk.fm/features/tap_dance

// Tap Dance declarations
enum {
  TD_GUI_D,
  TD_GUI_E,
  TD_GUI_A
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_E] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_E),
    [TD_GUI_D] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_D),
    [TD_GUI_A] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_A)
};


//キーマップの部分に、このように定義する。
//TD(TD_HOGEHOGE)
