#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>

#include "debug_print.h"


// Meyers_Effective_C++_55
// #include "main_meyers55.h"

int main(void) {
	printf("Searches time...\n");
	auto begin = std::chrono::steady_clock::now();

/**-----------------------------------------------------------------------------------**/
	// Check your code here!
	// Meyers_Effective_C_55::check_rules ();
/**-----------------------------------------------------------------------------------**/

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	printf("The time: %li µs\n", elapsed_ms.count());
	return EXIT_SUCCESS;
}
