CC= g++
CFLAGS= -Wall -std=c++11 -ggdb

main: main.cpp BinaryTree.h.gch
	$(CC) $(CFLAGS) -o main main.cpp
BinaryTree.h.gch: BinaryTree.h
	$(CC) $(CFLAGS) BinaryTree.h
valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-reachable=yes ./main
clean:
	rm -f main BinaryTree.h.gch
