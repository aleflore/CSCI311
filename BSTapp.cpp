#include "BSTapp.h"
int main()
{
	BST T;
	string command;
	string key;
	string satellite;
	while(cin >> command)
	{
		
		if(command == "insert")
		{
			cin >> key;
			cin.ignore();
			getline(cin, satellite);
			T.insert(key, satellite);
		}
		if(command == "find")
		{
			cin >> key;
			T.find(key);
		}
		if(command == "delete")
		{
			cin >> key;
			cin.ignore();
			getline(cin, satellite);
			T.remove(key, satellite);
		}
		if(command == "print")
		{
			T.print();
		}
		if(command == "quit")
		{
			return 0;
		}
	}
}