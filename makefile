CC = g++

CFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic

LDFLAGS = -lrt 

BST : BSTapp.o BST.o Node.o
	$(CC) $(LDFLAGS) BSTapp.o BST.o Node.o -o BST
		
BSTapp.o : BSTapp.cpp BSTapp.h
	$(CC) $(CFLAGS) BSTapp.cpp

BST.o : BST.cpp BST.h
	$(CC) $(CFLAGS) BST.cpp

Node.o : Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp
	
clean :
	rm BST *.o
