#include <iostream>
#include "tree.h"
using namespace std;

struct PersonRec {
	char name[20];
	int bribe;
	PersonRec * lChild;
	PersonRec * rChild;
	PersonRec();
	PersonRec(char*, int, PersonRec*, PersonRec*);
};

CTree::CTree()
{
	root = NULL;
}

PersonRec::PersonRec()
{
	bribe = 0;
	name[0] = '\0';
	lChild = NULL;
	rChild = NULL;
}

PersonRec::PersonRec(char* userName, int userBribe, PersonRec*, PersonRec*)
{
	strcpy(name, userName);
	bribe = userBribe;
	lChild = NULL;
	rChild = NULL;
}

CTree::~CTree()
{
	DeleteTree(root);
}

void CTree::DeleteTree(PersonRec * ptr)
{
	if (ptr != NULL)
	{
		DeleteTree(ptr->lChild);
		DeleteTree(ptr->rChild);
		delete ptr;
	}
}

void CTree::Add()
{
	char aName[20];
	int aBribe;
	cout << "\nEnter the person's name: ";
	cin >> aName; // assumes no embedded spaces in name
	cout << "\nEnter the person's contribution: ";
	cin >> aBribe;

	PersonRec * NewNode = new PersonRec(aName, aBribe, NULL, NULL); //This node is different than the node that gets created below. Think of this as just a temporary node that is made that just assigns the values of the user input using the four argument constructor. Then when this nodes values get passed to AddItem, the AddItem function will create a new node and copy the data from this node into the newly made node in Addtem(). See ****
																	//strcpy(NewNode->name, aName);
																	//NewNode->bribe = aBribe;
																	//NewNode->lChild = NULL;
																	//NewNode->rChild = NULL;

																	/*PersonRec * movingPointer;*/

																	//if (root == NULL)
																	//	root = NewNode;
																	//else if (root != NULL)
																	//{
																	//	/*movingPointer = root;*/
																	//	AddItem(root, NewNode->name, NewNode->bribe);
																	//}
	AddItem(root, NewNode->name, NewNode->bribe);
}

void CTree::AddItem(PersonRec *& ptr, char * NewName, int NewBribe)
{
	if (ptr != NULL) //When does the linking take place?
	{
		if (NewBribe > ptr->bribe)
		{
			AddItem((ptr->rChild), NewName, NewBribe);
			/*if (ptr->rChild != NULL)
			AddItem(ptr->rChild, NewName, NewBribe);
			else
			{

			}*/
		}
		else if (NewBribe < ptr->bribe)
		{
			AddItem(ptr->lChild, NewName, NewBribe);
		}
		else
		{
			cout << "Amount already exists. Please enter a different value.";
			return;
		}
	}
	else /*if (ptr == NULL)*/
	{
		PersonRec * NewNode = new PersonRec; //****This part creates the new node only when the program finds and empty spot, which is the else condition in this segment (ptr == NULL). That means when the program finds a spot where ptr equals NULL, it comes to this part, creates the node, then copies the data into it.
		NewNode->bribe = NewBribe;           //
		strcpy(NewNode->name, NewName);
		ptr = NewNode;
	}
}

void CTree::View()
{
	if (root == NULL)
		cout << "List is empty\n";
	else
		DisplayTree(root);
}

void CTree::DisplayTree(PersonRec * ptr)
{
	if (ptr != NULL)
	{
		DisplayTree(ptr->rChild);
		//DisplayTree(ptr->lChild); //Had to move this to after the cout so that it would display in descending order. **How do these double recursive calls work?**
		cout << "Name: " << ptr->name << "\t" << "Bribe Offered: " << ptr->bribe << endl;
		DisplayTree(ptr->lChild);
	}

}