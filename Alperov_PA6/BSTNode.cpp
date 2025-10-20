#include "BSTNode.h"

BSTNode::BSTNode()
{
	English = '\0';
	Morse = "";
	pLeft = nullptr;
	pRight = nullptr;
}

BSTNode::BSTNode(char English, string Morse)
{
	this->English = English;
	this->Morse = Morse;
	pLeft = nullptr;
	pRight = nullptr;
}

BSTNode::~BSTNode()
{
	//cout << "Destructor Activated" << endl; // optional
}

BSTNode* BSTNode::getLeft()
{
	return pLeft;
}

BSTNode* BSTNode::getRight()
{
	return pRight;
}

char BSTNode::getEnglish()
{
	return English;
}

string BSTNode::getMorse()
{
	return Morse;
}

void BSTNode::setLeft(BSTNode* Left)
{
	pLeft = Left;
}

void BSTNode::setRight(BSTNode* Right)
{
	pRight = Right;
}

void BSTNode::setEnglish(char EnglishText)
{
	English = EnglishText;
}

void BSTNode::setMorse(string MorseCode)
{
	Morse = MorseCode;
}
