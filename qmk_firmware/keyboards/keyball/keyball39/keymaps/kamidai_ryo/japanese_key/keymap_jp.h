//https://www.creativity-ape.com/entry/2021/02/11/110000
//https://docs.qmk.fm/features/tap_dance

   const uint16_t jp_us_list[][2] = {

    //左：英語配列  右：日本語   左：英語配列  右：日本語
    { KC_WBAK, KC_GRV },        // Zenkaku ↔︎ Hankaku ↔ Kanji (半角 ↔ 全角 ↔ 漢字)
    { KC_CIRC, KC_EQL },        // ^    =
    { KC_RETN, KC_INT3 },       // ¥
    { KC_AT, KC_LBRC },         // @    [
    { KC_LBRC, KC_RBRC },       // [    ]
    { KC_EXSL, KC_CAPS },       // Eisū (英数)
    { KC_COLN, KC_QUOT },       // :    '
    { KC_RBRC, KC_NUHS },       // ]    }
    { KC_BSLS, KC_INT1 },       // (backslash)
    { KC_MSEL, KC_INT5 },       // Muhenkan (無変換)
    { KC_PENT, KC_INT4 },       // Henkan (変換)
    { KC_RALT, KC_INT2 },       // Katakana ↔ Hiragana ↔ Rōmaji (カタカナ ↔ ひらがな ↔ ローマ字)
    { KC_HASH, S(KC_3) },       // #
    { KC_AMPR, S(KC_6) },       // &
    { KC_QUOT, S(KC_7) },       // '
    { KC_LPRN, S(KC_8) },       // (
    { KC_RPRN, S(KC_9) },       // )
    { KC_EQL,  S(KC_MINS) },    // =    -
    { KC_PEQL, S(KC_MINS) },    // =    -
    { KC_TILD, S(KC_EQL) },     // ~    =
    { KC_PIPE, S(KC_INT3) },    // |    [
    { KC_GRV,  S(KC_LBRC) },    // `
    { KC_LCBR, S(KC_RBRC) },    // {    }
    { KC_PLUS, S(KC_SCLN) },    // +    ;
    { KC_PPLS, S(KC_SCLN) },    // +    ;
    { KC_ASTR, S(KC_QUOT) },    // *    '
    { KC_PAST, S(KC_QUOT) },    // *    '
    { KC_RCBR, S(KC_NUHS) },    // }
    { KC_UNDS, S(KC_INT1) },    // _
    { KC_RCTL, KC_GRV },        // Zenkaku ↔︎ Hankaku ↔ Kanji (半角 ↔ 全角 ↔ 漢字)
    { KC_DQUO, S(KC_2) },       // "
    { KC_MENU, KC_LNG2 },       // Eisū (英数) on macOS
    { KC_MINS, KC_LNG1 }        // Kana (かな) on macOS
};
