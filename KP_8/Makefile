all: main.out

main.out: main.c src/list.c include/list.h
	gcc -Wall -Wextra -pedantic -o main.out main.c src/list.c -Iinclude

clean:
	rm -f main.out

run: all
	./main.out

.PHONY: all clean run