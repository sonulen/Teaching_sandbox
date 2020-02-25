# Set silence mode [default: true]
# If silence == off -> print usage commands
SILENCE := off
# Name of result file [%NAME%.elf] [default: run_me.elf]
NAME := sandbox
# Set optimization level [default: -0s]
OPTIMIZATION_LVL := -O0
# This adding `#define DEBUG` for your code. [default: `#define RELEASE`]
DEBUG := true
# Set c++ standard [default: -std=c++17]
CPP_STANDARD := -std=c++17
# Set GDB debuging info [default: if DEGUB_BUILD -> -g3 else None]
G_OPTION := -g3
# Enable generating asm files
ASM := on

DIRS := $(shell find . -not -path '*/\.*' -not -path '../builder' -type d)
SOURCES := $(shell find . -type f \( -name '*.c' -o -name '*.cpp' -o -name '*.s' -o -name '*.S' \))

PATH_TO_BUILDER = ../builder/builder.mk
include $(PATH_TO_BUILDER)
