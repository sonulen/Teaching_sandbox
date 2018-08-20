# Имя цели и итогового файла
TARGET := sand_box

# defines
DEFS :=

# Подключим настройки debug/release версии
include builder/settings.mk

.PHONY = clean all

export TARGET
export DEFS

all: .obj/$(MARK)
	@echo - Building $(TARGET)
	@make all -j4 --makefile=main.mk
	@echo - Building features
	@make all -j4 --makefile=features/makefile
	@echo - Building meyers55
	@make all -j4 --makefile=meyers55/makefile
	@echo - Executing linker
	@make all -j4 --makefile=builder/link.mk

