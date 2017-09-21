#include "BST.h"
BST::BST()
{
	root = NULL;
}
BST::~BST()
{}
void BST::insert(string key, string satellite)
{
	k = new string;
	s = new string;
	*k = key;
	*s = satellite;
	Node * z = new Node(k,s,NULL);
	if(root)
	{
		Node * tmp = find(satellite,key,root);
		if(tmp)
		{
			return;
		}
	}
	Node * y = NULL;
	Node * x = root;
	while(x)
	{
		y = x;
		if(*(z->key) < *(x->key))
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if(!y)
	{
		root = z;
	}
	else if(*(z->key) < *(y->key))
	{
		y->left = z;		
	}
	else
	{
		y->right = z;
	}
}
void BST::remove(string key, string data)
{
	Node * z = find(data,key,root);
	tree_delete(z);
}
void BST::tree_delete(Node * z)
{
	Node * y = NULL;
	if(!z)
	{
		return;
	}
	if(z->left == NULL)
	{
		transplant(z,z->right);
	}
	else if(z->right == NULL)
	{
		transplant(z,z->left);
	}
	else
	{
		y = tree_minimum(z->right);
		if(y->parent != z)
		{
			transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
	z->left = NULL;
	z->right = NULL;
}
void BST::find(string key)
{
	Node * x = root;
	while(x)
	{
		if(key < *(x -> key))
		{
		  x = x -> left;
		}
		else if (key == *(x -> key))
		{
		  cout << *(x -> key) << " " << *(x -> data) << endl;
		  x = x -> right;
		}
		else
		{
		  x = x -> right;
		}
	}
}
Node * BST::find(string data, string key, Node * t)
{ 
	if(!t)
	{
		return NULL;
	}
	if(*(t->key) == key && *(t->data) == data)
	{
		return t;
	}
	if(key < *(t->key))
	{
		return find(data,key,t->left);
	}
	else
	{
		return find(data,key,t->right);
	}
}
void BST::print()
{
	if(root)
	{
		print(root, 0);
	}
}
void BST::print(Node * x, int depth)
{
	if(x != NULL)
	{
		print(x->left, depth+1);
		cout << depth << " " << *(x->key) << " " << *(x->data) << endl;
		print(x->right, depth+1);
	}
}
void BST::transplant(Node * u, Node * v)
{
	if(u->parent == NULL)
	{
		root = v;
	}
	else if(u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	if(v != NULL)
	{
		v->parent = u->parent;
	}
}
Node * BST::tree_minimum(Node * x)
{
	while(x->left)
	{
		x = x->left;
	}
	return x;
}
