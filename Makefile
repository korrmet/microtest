all: test

example: example.c microtest.h
	$(CC) example.c -o example

.PHONY: clean test

test: example
	./example

clean:
	rm -rf example
