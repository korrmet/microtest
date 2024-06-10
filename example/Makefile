all: main

# linking
main: main.o example.o
	gcc main.o example.o -o main

# main module
main.o: main.c
	gcc -c main.c -o main.o

# exaple module
example.o: example.c example.h
	gcc -c example.c -o example.o
example.c: example.test_passed
example.h: example.test_passed
example.test: example.test.c
	gcc example.test.c example.c -o example.test -I../ -ansi -Wall -pedantic
example.test_passed: example.test
	rm -f example.test_passed
	./example.test 1>&2
	touch example.test_passed

clean:
	rm -rf main *.o *.test *.test_passed

compile_commands.json: clean
	compiledb make
