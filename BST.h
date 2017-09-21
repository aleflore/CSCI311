#include <string>
#include <fstream>
#include <iostream>
#pragma once
#include "Node.h"
#ifndef BST_H
#define BST_H
/**
* algorithms for the BST functions
**/
using namespace std; 
class BST
{
	private:
		Node * root;
		string * s;
		string * k;
		void tree_delete(Node *);	
		Node * find(string, string, Node *);
		void print(Node *, int);
		void transplant(Node *, Node *);
		Node * tree_minimum(Node *);
	public:
		BST();
		~BST();
		void insert(string,string);
		void remove(string,string);
		void find(string);
		void print();
		void quit();		
};
#endif