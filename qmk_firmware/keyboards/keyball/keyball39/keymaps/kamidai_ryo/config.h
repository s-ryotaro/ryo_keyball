/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#ifdef RGBLIGHT_ENABLE
// 容量削減のため以下をオミット
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
//#endif

#define COMBO_COUNT 6
#define COMBO_TERM 40 //デフォルトでは、コンボが認識されるまでのタイムアウトは 50 ミリ秒に設定されています。コンボが誤って失敗する、またはキーを同時に押すのが難しい場合は、この設定を変更できます

#define KEYBALL_SCROLLSNAP_ENABLE 0  // scrollsnapをオフにする

#define TAP_CODE_DELAY 5
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define KEYBALL_CPI_DEFAULT 1000       // 光学センサーPMW3360DM の解像度 (CPI) の規定値
#define KEYBALL_SCROLL_DIV_DEFAULT 6  // スクロール速度の規定値

// ファームウェアのサイズを削減
#define NO_ACTION_ONESHOT  // 392バイト

// #define IGNORE_MOD_TAP_INTERRUPT  // 10バイト
// #define TAPPING_FORCE_HOLD  // 34バイト
// 下記三つで444バイト
#define TAPPING_TERM 175
// #define PERMISSIVE_HOLD
// #define RETRO_TAPPING