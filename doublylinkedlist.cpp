/** Adrian LeFLore
*  CSCI 311
*  Assignment 1
**/

#include "doublylinkedlist.h"
// Constructs  doubly-linked list
DoublyLinkedList::DoublyLinkedList()
{head = tail = current = NULL;}

//destructs doubly-linked list
DoublyLinkedList::~DoublyLinkedList()
{
	Node * ptr = head;
	while(!ptr)
	{
		Node * temp = ptr;
		ptr = ptr -> next;
		delete temp;
	}
	head = tail = current = NULL;
}
	
//adds to end of list  
void DoublyLinkedList::append(const string &add)
{
	Node * n = new Node(add);
	if(!head)
	{
	    n -> next = NULL; 
	    n -> prev = NULL;
	    head = tail = current = n;
	}
	else
	{
		n -> next = NULL;
		n -> prev = tail;
		tail -> next = n;
		tail = current = n;
	}
}

//insert data before current song
void DoublyLinkedList::insertBefore(const string &target)
{
    Node * n = new Node(target);
	if(!current) 
	{
		current = head = tail = n;
	}
	 else if(current == head)
	{
		current -> prev = n;
		n -> prev = NULL;
		n -> next = current;
		head = current = n;
	}
	else 
	{
	    current -> prev -> next = n;
	    n -> prev = current -> prev;
	    n -> next = current;
	    current -> prev = n;
		current = n;		
	}
}

//insert a data after current song
void DoublyLinkedList::insertAfter(const string &target)
{
    Node * n = new Node(target);
	if(!current)
	{
		current = head = tail = n;
	}
	else if(current == tail && current != head)
	{
		current->next = n;
        n->prev = current;
        n -> next = NULL;
        tail = current = n;
	}
	else
	{
        current->next->prev = n;
        n -> next = current -> next;
        n -> prev = current;
        current->next = n;
        current = n;
	}
}

//if the data is in the list remove the pointer to it
void DoublyLinkedList::remove(const string &target)
{
	if (head != NULL) {
        bool flag = false;
        for (Node *ptr = head; ptr != NULL && flag == false; ptr = ptr->next) {
            if (*(ptr->data) == target) {
                flag = true;
                // Node is the only element in the list
                if (ptr == head && ptr == tail) {
                    head = tail = current = NULL;
                    delete ptr;
                }
                // Node is at the beginning of a list with more than one element
                else if (ptr == head && ptr->next != NULL) {
                    head = current = ptr->next;
                    ptr->next->prev = NULL;
                    delete ptr;
                }
                // Node is at the end of a list containing more than one element
                else if (ptr == tail && ptr->prev != NULL) {
                    if (current == ptr)
                        current = ptr->prev;
                    tail = ptr->prev;
                    ptr->prev->next = NULL;
                    delete ptr;
                }
                // Node is between two elements
                else {
                    if (current == ptr)
                        current = ptr->next;
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    delete ptr;
                }
            }
        }
    }
}

//set current to the first song
void DoublyLinkedList::begin()
{
		current = head;
}	

//set current to the last song
void DoublyLinkedList::end()
{

		current = tail;
}

//progress current
bool DoublyLinkedList::next()
{
	if(current->next)
	{
		current = current->next;
		return true;
	}
	return false;
}

//regress current
bool DoublyLinkedList::prev()
{
	if(current->prev)
	{
		current = current->prev;
		return true;
	}
	return false;
}

//if the target in the list return it
bool DoublyLinkedList::find(const string &target)
{
	Node *ptr = head;
    while (ptr) 
    {
        if (*(ptr->data) == target)
        {
            current = ptr;
            return true;
        }
        else 
            ptr = ptr->next;
    }
    return false;
}
