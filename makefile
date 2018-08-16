# Имя цели и итогового файла
TARGET := sand_box

# defines
DEFS := DEBUG_FLAG

.PHONY = clean all

all:
	@echo - Building $(TARGET)
	@make all -j4 --makefile=main.mk
	@echo - Building features
	@make all -j4 --makefile=features/makefile
	@echo - Building meyers55
	@make all -j4 --makefile=meyers55/makefile
	@echo - Executing linker
	@make all -j4 --makefile=builder/link.mk

# По умолчанию Clean мне так удобно
clean:
	rm -rf .d
	rm -rf .obj