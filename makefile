CC= g++
CFLAGS= -Wall -std=c++11 -ggdb

main: main.cpp BinaryTree.h.gch
	$(CC) $(CFLAGS) -o main main.cpp
BinaryTree.h.gch: BinaryTree.h
	$(CC) $(CFLAGS) BinaryTree.h
clean:
	rm -f main BinaryTree.h.gch
