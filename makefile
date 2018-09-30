all: str.o
	gcc str.o

run:
	./a.out

str.o: str.c str.h
	gcc -c str.c str.h
