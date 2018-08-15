# Имя цели и итогового файла
TARGET = sand_box

# defines
DEFS := DEBUG_FLAG

# Путь к подключаемым директориям
include features/dirs.mk
include meyers55/dirs.mk

# Все исходники
SOURCE := sand_box.cpp

.PHONY = clean all

# По умолчанию Clean мне так удобно
clean:
	rm -rf .d
	rm -rf .obj	

include builder/compile.mk

all: bin/$(TARGET).elf
	@echo -Building meyers55
	@make  all -j4 --makefile=meyers55/makefile
	@echo - Executing linker
	@make  all -j4 --makefile=builder/link.mk




