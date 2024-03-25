funcptr: obj
	gcc fib.o -o fib main.c

macro-fast: obj
	gcc fib.o -DMACRO_FAST -o fib main.c

macro-slow: obj
	gcc fib.o -DMACRO_SLOW -o fib main.c

obj:
	gcc fib.c -c

clean:
	rm -f *.o
	rm -f fib