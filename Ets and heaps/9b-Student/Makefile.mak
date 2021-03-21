make:heap.o main.o
	gcc -o make main.o heap.o
heap.o:heap.c heap.h
	gcc -c heap.c heap.h
main.o:heap.h main.c
	gcc -c heap.h main.c