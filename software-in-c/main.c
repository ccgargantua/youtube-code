#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "fib.h"


// The fibonaccia method used will either be decided
// at compile time by a macro or at runtime via user
// input if neither macro is defined.
#if defined(MACRO_FAST)
    #define fib fast_fib
#elif defined(MACRO_SLOW)
    #define fib slow_fib
#else
    #define fib fib
#endif


// Our conditional compilation directives that influence
// how we handle our args can be confusing, so we will
// go ahead and offload this task to a separate function
// to keep things spread out.
int setups_args(int argc, char **argv);


int main(int argc, char **argv)
{
    // We can report invalid args in the return value,
    // and in the case of invalid args we can handle
    // accordingly (in our case, exiting the program)
    int iterations = setups_args(argc, argv);
    if(iterations <= 0)
        return 1;

    // This is just our loop for calculating the fibonacci
    // sequence up to a specified number of iterations
    unsigned long last = 0;
    bool overflow = false;
    clock_t start_time = clock();
    for(int i = 0; i < iterations; i++)
    {
        clock_t loop_start_time = clock();
        unsigned long value = fib(i);
        double time_spent = (double)(clock() - loop_start_time) / CLOCKS_PER_SEC;

        printf("%d: ", i);

        // When we encounter overflow, it would probably
        // be wise to just stop printing the results. We
        // can still "calculate" the value for the rest of
        // the iterations, though.
        if(!overflow)
        {
            if(value >= last)
            {
                printf("%ld", value);
                last = value;
            }
            else
            {
                overflow = true;
                printf("OVERFLOW");
            }
        } else
            printf("OVERFLOW");
        printf("(%0.5lf seconds)\n", time_spent);
    }

    return 0;
}


int setups_args(int argc, char **argv)
{
    if(argc < 2)
    {
        // In the case of funcptr build, we give the option
        // of choosing between fast and slow algorithms
        #if !defined(MACRO_FAST) && !defined(MACRO_SLOW)
        printf("Usage: ./main <iterations> [fast/slow]\n");

        // Otherwise, we won't prompt for that extra optional
        // argument
        #else
        printf("Usage: ./main <iterations>\n");
        #endif

        return -1;
    }



    // To avoid crashing, we can be meticulous when checking
    // for a valid numeric argument for iterations...
    for(int i = 0; i< strlen(argv[1]); i++)
        if(!isdigit(argv[1][i]))
        {
            printf("Input %s is not a number.\n", argv[1]);
            return -1;
        }

    // ... and also for a valid option for our algorithm
    //     argument.
    #if !defined(MACRO_FAST) && !defined(MACRO_SLOW)
    if(argc == 3)
    {
        if(strcmp(argv[2], "fast") == 0)
            set_fib_func(fast_fib);
        else if(strcmp(argv[2], "slow") == 0)
            set_fib_func(slow_fib);
    }
    #endif

    return atoi(argv[1]);
}