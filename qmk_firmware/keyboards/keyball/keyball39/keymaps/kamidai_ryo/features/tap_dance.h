//https://yakinikunotare.boo.jp/orebase2/keyboard/diy_keyboard/qmk/tap_dance/start
//https://docs.qmk.fm/features/tap_dance

// Tap Dance declarations
enum {
  TD_GUI_D,
  TD_GUI_E,
  TD_CTL_A
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_E] = ACTION_TAP_DANCE_DOUBLE(KC_E,LGUI(KC_E)),
    [TD_GUI_D] = ACTION_TAP_DANCE_DOUBLE(KC_D,LGUI(KC_D)),
    [TD_CTL_A] = ACTION_TAP_DANCE_DOUBLE(KC_A,LCTL(KC_A))
};


//キーマップの部分に、このように定義する。
//TD(TD_HOGEHOGE)
