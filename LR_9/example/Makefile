cc=gcc
flags=-std=c11
buildDir=build

all: buildDir main.o
	$(cc) $(flags) $(buildDir)/main.o -o ./$(buildDir)/main.out

buildDir: ./$(buildDir)
	mkdir -p $(buildDir)

main.o: ./main.c
	$(cc) $(flags) ./main.c -c -o $(buildDir)/main.o
	
