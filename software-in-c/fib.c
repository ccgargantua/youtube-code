#include "fib.h"


// Our hidden function pointer to the algorithm
// of our choice.
static unsigned long (*fib_func)(unsigned long) = fast_fib;


// Recursion can be easy and small :)
unsigned long slow_fib(unsigned long n)
{
    if(n <= 1)
        return n;
    return slow_fib(n-1) + slow_fib(n- 2);
}


// Recursion is slow!!!
unsigned long fast_fib(unsigned long n)
{
    unsigned long a, b, c=0;
    for(int i = 0; i < n; i++)
    {
        if(i <= 1)
        {
            a = 0;
            b = 1;
        }
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}


unsigned long fib(unsigned long n)
{
    return fib_func(n);
}


void set_fib_func(unsigned long (*func)(unsigned long))
{
    fib_func = func;
}