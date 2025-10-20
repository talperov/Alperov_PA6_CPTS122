#pragma once
#include "BSTNode.h"
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class BST
{
private:

	BSTNode* pRoot;

	void insertRec(BSTNode* pNode, char English, string Morse);
	string searchRec(BSTNode* pNode, char Searching) const;
	void printRec(BSTNode* pNode);
	void deleteRec(BSTNode* pNode);

public:

	BST();
	~BST();

	bool isEmpty() const;
	void insert(char English, string Morse);
	string search(char Searching) const;
	void print();
	void openFile(string& infile);
};


