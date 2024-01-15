CC = clang
CFLAGS = -Werror -std=c11 -Wall -Wextra

all: one two

one:
	@echo "Building one"
	$(CC) $(CFLAGS) 1.c -o one

two:
	@echo "Building two"
	$(CC) $(CFLAGS) 2.c -o two

clean:
	@echo "Cleaning"
	rm -f one
	rm -f two