# Имя цели и итогового файла
TARGET = sand_box

DIRS_OBJ := .obj/
DIRS_BIN := bin/
DIRS_DEPS := .d/

# Все исходники
SOURCE := $(shell find . -name "*.cpp")

# Путь к локальным директориям
DIRS := ./

include features/dirs.mk

# defines
DEFS :=

# Объекты формируем
OBJECTS = $(SOURCE:.cpp=.o)
OBJS = $(addprefix .obj/,$(OBJECTS))

# Флаги компиляции
CPP := g++
OPTIM := -O0
BFLAGS += -Wall -g3 -Wextra -Werror -flto
CPPFLAGS += $(OPTIM) $(BFLAGS) -std=c++17 -pthread

# Флаги линковки
LD := g++
CFLAGS = -Wall -g3 -Wextra -Werror -pthread
LDFLAGS := --gc-sections
LDFLAGS += -o bin/$(TARGET).elf -Map bin/$(TARGET).map
LDOPTS:= $(addprefix -Xlinker ,$(LDFLAGS)) -lm

OBJDUMP := objdump
SIZE := size

# Формируем зависимости
DEPS = $(addprefix $(DIRS_DEPS),$(OBJS:.o=.d))
#DEPFLAGS = -MT $@ -MMD -MP -MF .d/$*.Td
DEPFLAGS = -MMD -MP -MF .d/$*.Td
DIRFLAGS = $(addprefix -I, $(DIRS))
DEFFLAGS = $(addprefix -D,$(DEFS))

#this would rename temporary dep files (.Td) into final *.d ones
POSTCOMPILE = @mv -f .d/$*.Td .d/$*.d && touch $@

#directory, where this (makefile) file is located (for dependancy)
ROOT_DIR := $(notdir $(CURDIR))
PROJ_DIR := $(dir $(firstword $(MAKEFILE_LIST)))
MAKEFILE_DEPS := $(PROJ_DIR)/Makefile 

.PHONY = clean all
# По умолчанию Clean мне так удобно
clean:
	rm -rf .d
	rm -rf .obj
	
# Подтягиваем зависимости
-include $(DEPS)

# compile and generate dependency info
.obj/%.o: %.cpp  $(MAKEFILE_DEPS) 
	@echo [CPP] $<
	@mkdir -p $(dir .d/$<)
	@mkdir -p $(dir .obj/$<)
	@$(CPP) $(CPPFLAGS) $(DEPFLAGS) $(DIRFLAGS) $(DEFFLAGS) -c $< -o $@
	@$(POSTCOMPILE)
	
all: bin/$(TARGET).elf

bin/$(TARGET).elf:	$(OBJS)
# Linker
	@mkdir -p bin
	@echo [LD] bin/$(TARGET).elf
	@$(LD) $(CFLAGS) $(OBJS) $(LDOPTS)
	@$(OBJDUMP) --source -D bin/$(TARGET).elf > bin/$(TARGET).asm
	@echo
	@echo 'Size summary:'
	@$(SIZE)  --format=berkeley bin/$(TARGET).elf


