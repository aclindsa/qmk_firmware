# MCU name
MCU = STM32F072

CONSOLE_ENABLE = no
COMMAND_ENABLE = no
CUSTOM_MATRIX = no
ENCODER_ENABLE = yes
EXTRAKEY_ENABLE = yes
OLED_DRIVER_ENABLE = yes # If no display is plugged in and CONSOLE_ENABLE = yes, the firware gets stuck
WPM_ENABLE = yes

# Laptop users may want to enable low-power on idle thread 
# OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE