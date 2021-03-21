make:trie.o main.o
	gcc -o make main.o trie.o
trie.o:trie.c trie.h
	gcc -c trie.c trie.h
main.o:trie.h main.c
	gcc -c trie.h main.c