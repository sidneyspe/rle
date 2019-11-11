all: main


RLE.o : rle.c rle.h
	gcc -g -c rle.c -o RLE.o
	
main: RLE.o main.c
	gcc -g main.c RLE.o -o main

clean:
	rm *.o