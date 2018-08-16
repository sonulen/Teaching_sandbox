# Имя цели и итогового файла
TARGET := sand_box

# defines
DEFS :=

debug: DEFS += DEBUG_FLAG
debug: .obj/debug_mark all
	find .obj/ -iname "new_debug_mark" -exec mv -f .obj/new_debug_mark .obj/debug_mark \;

.PHONY = clean all

export TARGET
export DEFS

# По умолчанию Clean мне так удобно
clean:
	rm -rf .d
	rm -rf .obj

all: .obj/new_debug_mark 
	@echo - Building $(TARGET)
	@make all -j4 --makefile=main.mk
	@echo - Building features
	@make all -j4 --makefile=features/makefile
	@echo - Building meyers55
	@make all -j4 --makefile=meyers55/makefile
	@echo - Executing linker
	@make all -j4 --makefile=builder/link.mk
	@rm -f .obj/debug_mark
	
prepare:
	find .obj/ -iname "debug_mark" -exec mv -f .obj/debug_mark .obj/new_debug_mark \;
	
.obj/debug_mark: 
	@make clean
	@mkdir .obj
	@touch .obj/new_debug_mark
	
.obj/new_debug_mark:
	@make clean
	@mkdir .obj
	@touch .obj/new_debug_mark