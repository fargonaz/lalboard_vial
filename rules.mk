# MCU name
MCU = RP2040
BOOTLOADER = rp2040

SERIAL_DRIVER = vendor

CUSTOM_MATRIX = lite

#q Project specific files
SRC = matrix.c
TAP_DANCE_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
VIAL_INSECURE = yes
CAPS_WORD_ENABLE = yes
