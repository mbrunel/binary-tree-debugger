all: example

example: main.c example.c ../binary_tree_debugger.h
	gcc -g -Wall -Wextra main.c example.c -I.. -o example

clean:
	rm example
