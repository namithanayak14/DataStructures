make:hash.o main.o
	gcc -o make main.o hash.o
hash.o:hash.c hash.h
	gcc -c hash.c hash.h
main.o:hash.h main.c
	gcc -c hash.h main.c