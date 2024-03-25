#ifndef FIB_H
#define FIB_H

#include <stdio.h>


// A recursive and slow algorithm for the
// fibonacci sequence
unsigned long slow_fib(unsigned long n);


// An in-place and fast algorithm for the
// fibonacci sequence
unsigned long fast_fib(unsigned long n);


// We call our function pointer here
unsigned long fib(unsigned long n);


// We set the function we want pointed to by
// our function pointer here. We do this in a
// function to preserve the layer of abstraction.
// This function is global and allows you to
// change what function is being pointed to by
// the hidden function pointer.
void set_fib_func(unsigned long (*func)(unsigned long));


#endif