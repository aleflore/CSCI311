#include <string>
#include <fstream>
#include <iostream>
#pragma once
#ifndef NODE_H
#define NODE_H
using namespace std;
/**
* Node class holds all pointers
* and creates strings
**/
class Node
{
	public:
		string * key; 
		string * data;
		Node * left;
		Node * right; 
		Node * parent;
		Node();
		~Node ();
		Node(string * date, string * satellite, Node *); 
};
#endif
		