#include "Node.h"
Node::Node(string * date, string * satellite, Node * p)
{
key = date;
data = satellite;
left = NULL;
right = NULL;
parent = p;
}
Node::~Node()
{
	delete left;
	delete right;
	delete key;
	delete data;
	delete parent;
}