#pragma once
struct PersonRec;

class CTree {
private:
	PersonRec * root;
	void AddItem(PersonRec*&, char*, int);
	void DisplayTree(PersonRec *);
	void DeleteTree(PersonRec *);

public:
	CTree();
	~CTree();
	void Add();
	void View();
};
