DIRS_meyers55 := rules_3/ rules_4/ rules_7/ rules_12/ rules_15/ rules_24/ rules_25/
DIRS += meyers55
DIRS += $(addprefix meyers55/,$(DIRS_meyers55))