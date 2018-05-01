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

int main(void) {
	printf("Searches time...\n");
	auto begin = std::chrono::steady_clock::now();
	// templates
	main_templates();
	//usleep(1000);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	printf("The time: %li µs\n", elapsed_ms.count());
	return EXIT_SUCCESS;
}
