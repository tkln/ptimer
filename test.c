#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ptimer.h"

int main(void)
{
    struct ptimer_interval test;

    ptimer_start(&test);
    ptimer_end(&test);
    ptimer_fprint(stdout, "zero: ", &test);

    ptimer_start(&test);
    sleep(1);
    ptimer_end(&test);
    ptimer_fprint(stdout, "one: ", &test);

    return EXIT_SUCCESS;
}
