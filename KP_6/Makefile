all: generator.out reader.out searcher.out

generator.out: generator.c src/computer.c include/computer.h
	gcc -o generator.out generator.c src/computer.c -Iinclude

reader.out: reader.c src/computer.c include/computer.h
	gcc -o reader.out reader.c src/computer.c -Iinclude

searcher.out: searcher.c src/computer.c include/computer.h
	gcc -o searcher.out searcher.c src/computer.c -Iinclude

clean:
	rm -f generator.out reader.out searcher.out computer.bin db.bin

run: all
	./generator.out 10 | ./reader.out computer.bin
	./searcher.out computer.bin 2

.PHONY: all clean run