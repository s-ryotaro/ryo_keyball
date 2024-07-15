//https://yakinikunotare.boo.jp/orebase2/keyboard/diy_keyboard/qmk/tap_dance/start
//https://docs.qmk.fm/features/tap_dance

// Tap Dance declarations
enum {
  TD_GUI_D,
  TD_GUI_E,

  TD_CTL_A,
  TD_CTL_Z,
  TD_CTL_X,
  TD_CTL_C,
  TD_CTL_V,

  TD_MINUS_TO_UNDUNDER,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_E] = ACTION_TAP_DANCE_DOUBLE(KC_E,LGUI(KC_D)),
    [TD_GUI_D] = ACTION_TAP_DANCE_DOUBLE(KC_D,LGUI(KC_E)),

    [TD_CTL_A] = ACTION_TAP_DANCE_DOUBLE(KC_A,LCTL(KC_A)),
    [TD_CTL_A] = ACTION_TAP_DANCE_DOUBLE(KC_A,LCTL(KC_Z)),
    [TD_CTL_A] = ACTION_TAP_DANCE_DOUBLE(KC_A,LCTL(KC_X)),
    [TD_CTL_A] = ACTION_TAP_DANCE_DOUBLE(KC_A,LCTL(KC_C)),
    [TD_CTL_A] = ACTION_TAP_DANCE_DOUBLE(KC_A,LCTL(KC_V)),
    
    [TD_MINUS_TO_UNDUNDER] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS,KC_UNDS),
};


//キーマップの部分に、このように定義する。
//TD(TD_HOGEHOGE)
