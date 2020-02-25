#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>

#include "debug_print.h"
#include "is_pointer_impl.h"

// Meyers_Effective_C++_55
// #include "main_meyers55.h"

int main(void) {
    printf("Searches time...\n");
    auto begin = std::chrono::steady_clock::now();

    int                         x   = 200;
    [[maybe_unused]] int*       px  = &x;
    [[maybe_unused]] const int* cpx = px;
    [[maybe_unused]] int&       rx  = x;
    [[maybe_unused]] const int& crx = x;

    check_is_pointer(x);
    check_is_pointer(px);
    check_is_pointer(cpx);
    check_is_pointer(rx);
    check_is_pointer(crx);

    /**-----------------------------------------------------------------------------------**/
    // Check your code here!
    // Meyers_Effective_C_55::check_rules ();
    /**-----------------------------------------------------------------------------------**/

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    printf("The time: %li µs\n", elapsed_ms.count());
    return EXIT_SUCCESS;
}
