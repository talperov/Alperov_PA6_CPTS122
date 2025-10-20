#pragma once
#include <iostream>
#include <string>

using std::string;

class BSTNode
{
		
private:

	char English; // English Text Character
	string Morse; // Morse Code
	BSTNode* pLeft; // Child Pointers
	BSTNode* pRight; // CHild Pointers

public:

	//Constructors Copy Constructors Destructors
	BSTNode();
	BSTNode(char English, string Morse);
	~BSTNode();

	//getters
	BSTNode* getLeft();
	BSTNode* getRight();
	char getEnglish();
	string getMorse();

	//setters
	void setLeft(BSTNode* Left);
	void setRight(BSTNode* Right);
	void setEnglish(char EnglishText);
	void setMorse(string MorseCode);

	//members
	
	//will add member functions if needed.

};

