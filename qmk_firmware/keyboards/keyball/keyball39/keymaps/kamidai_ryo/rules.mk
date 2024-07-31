# RGBLIGHT_ENABLE = yes

OLED_ENABLE = yes

VIA_ENABLE = yes

EXTRAKEY_ENABLE = yes

COMBO_ENABLE = yes

TAP_DANCE_ENABLE = yes

OS_DETECTION_ENABLE = yes

MACRO_ENABLE = yes

### 使っていないもの
### 以下はメモリ不足のため、VIAをOFFにする必要がある
KEY_OVERRIDE_ENABLE = no

AUTO_SHIFT_ENABLE = no

# ファームウェアのサイズを削減
# EXTRAFLAGS += -flto
GRAVE_ESC_ENABLE = no  # 90バイト

###https://zenn.dev/koron/articles/98324ab760e83a
LTO_ENABLE = yes

CONSOLE_ENABLE = no

COMMAND_ENABLE = no

SPACE_CADET_ENABLE = no

MOUSEKEY_ENABLE = no

MAGIC_ENABLE = no

MUSIC_ENABLE = no