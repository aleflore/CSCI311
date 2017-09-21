#ifndef doublylinkedlist_h
#define doublylinkedlist_h
#include <iostream>
#include <string>
using std::string;
class DoublyLinkedList{
private:
    class Node{
    public:
    Node(const string &song) 
    {string * d = new string; *d = song; data = d;}
    ~Node() {delete data;}
    Node * next;
    Node * prev; 
    string *data;
    }; 
public:
Node * head;
Node * tail;
Node * current;
DoublyLinkedList();
~DoublyLinkedList();
void append(const string &s);
void insertBefore(const string &s);
void insertAfter(const string &s);
void remove(const string &s);
bool empty() {return !head ? true : false;}
void begin();
void end();
bool next();
bool prev();
bool find(const string &s);
const string &getData() {return *(current->data);}
};
#endif
