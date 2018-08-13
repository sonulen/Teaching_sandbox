//============================================================================
// Name        : sand_box.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>

// templates
#include "main_templates.h"
#include "parameter_pack.h"

// debug var alert
#include "debug_var.h"

//
#include "main_meyers55.h"

int main(void) {
	printf("Searches time...\n");
	auto begin = std::chrono::steady_clock::now();

	//meyers55
	check_rules();

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	printf("The time: %li µs\n", elapsed_ms.count());
	return EXIT_SUCCESS;
}
