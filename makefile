include dirs.mk
include features/dirs.mk
include sb_meyers55/dirs.mk

# Все исходники
SOURCE := $(shell find sb_meyers55/ -name "*.cpp")

include builder/compile.mk