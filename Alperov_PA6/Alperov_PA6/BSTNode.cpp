#include "BSTNode.h"
using std::cout;
using std::cin;
using std::endl;

BSTNode::BSTNode()
{
	English = '\0';
	Morse = "";
	pLeft = nullptr;
	pRight = nullptr;

}

BSTNode::BSTNode(char English, std::string Morse)
{
	this->English = English;
	this->Morse = Morse;
	pLeft = nullptr;
	pRight = nullptr;
}

BSTNode::~BSTNode()
{
	cout << "Destructor Activated" << endl; // Remember to delete this
}

BSTNode* BSTNode::getLeft()
{
	return this->pLeft;
}

BSTNode* BSTNode::getRight()
{
	return this->pRight;
}

char BSTNode::getEnglish()
{
	return this->English;
}

string BSTNode::getMorse()
{
	return this->Morse;
}

void BSTNode::setLeft(BSTNode* Left)
{
	this->pLeft = Left;
}

void BSTNode::setRight(BSTNode* Right)
{
	this->pRight = Right;
}

void BSTNode::setEnglish(char EnglishText)
{
	this->English = EnglishText;
}

void BSTNode::setMorse(string MorseCode)
{
	this->Morse = MorseCode;
}

