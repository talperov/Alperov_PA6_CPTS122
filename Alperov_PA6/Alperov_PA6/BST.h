#pragma once
#include "BSTNode.h"
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

class BST
{
private:

	BSTNode* pRoot; // Similar to pTop that would be used in Stacks
	void printRec(BSTNode* pNode);
	void deleteRec(BSTNode* pNode);

public:

//Constructors Copy Constructor and Destructor
	BST();
	~BST();

//getters

	// No Getters Needed

//setters

	// No Setters Needed

//members

	bool isEmpty() const;
	void insert(char English, string Morse);
	void print();
	string search(char Searching) const;
	void openFile(string& infile);

};

