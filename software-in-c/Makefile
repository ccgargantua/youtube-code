BUILD_DIR = ./build

all: funcptr macro-fast macro-slow

funcptr: obj
	gcc $(BUILD_DIR)/fib.o -o $(BUILD_DIR)/$@ main.c

macro-fast: obj
	gcc $(BUILD_DIR)/fib.o -DMACRO_FAST -o $(BUILD_DIR)/$@ main.c

macro-slow: obj
	gcc $(BUILD_DIR)/fib.o -DMACRO_SLOW -o $(BUILD_DIR)/$@ main.c

obj:
	mkdir -p $(BUILD_DIR)
	gcc fib.c -c -o $(BUILD_DIR)/fib.o

clean:
	rm -f $(BUILD_DIR)/*