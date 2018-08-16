# Путь к подключаемым директориям
include dirs.mk
include features/dirs.mk
include meyers55/dirs.mk

# Все исходники
SOURCE := sand_box.cpp

include builder/compile.mk
