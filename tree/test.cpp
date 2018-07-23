#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include "tree.h"

int displayMenu(void);
void processChoice(int, CTree&);

int main(void)
{
	int num;
	CTree ct;
	do
	{
		num = displayMenu();
		if (num != 3)
			processChoice(num, ct);
	} while (num != 3);
	return 0;
}

int displayMenu(void)
{
	int choice;
	cout << "\nMenu\n";
	cout << "==============================\n\n";
	cout << "1. Add student to waiting list\n";
	cout << "2. View waiting list\n";
	cout << "3. Exit program\n\n";
	cout << "Please enter choice: ";
	cin >> choice;
	return choice;
}

void processChoice(int choice, CTree& myTree)
{
	switch (choice)
	{
	case 1: myTree.Add(); break;
	case 2: myTree.View(); break;
	}
}