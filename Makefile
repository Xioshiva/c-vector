CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g -std=c11 -O3
CFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer
LDFLAGS=-lm
LDFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer

all: main compile_test

main: main.o vector.o error.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDFLAGS_ASAN)

vector.o: vector.c vector.h error.h error.c
	$(CC) -c $< $(CFLAGS) $(CFLAGS_ASAN)

error.o: error.c error.h
	$(CC) -c $< $(CFLAGS) $(CFLAGS_ASAN)

compile_test: vector.o error.o test/test_vector.c
	$(CC) test/test.c $^ -o test/test $(LIBS) $(CFLAGS) $(CFLAGS_ASAN) -lcunit

test: compile_test
	./test/test

clean:
	rm -f *.o main test/test