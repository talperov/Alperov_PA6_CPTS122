#include "BST.h"

BST::BST()
{
	pRoot = nullptr;
	string morseFile = "MorseTable.txt";
	openFile(morseFile);
}

BST::~BST()
{
	deleteRec(pRoot);
	pRoot = nullptr;
	cout << "Destructor Activated" << endl;
}

bool BST::isEmpty() const
{
	return pRoot == nullptr;
}

void BST::insertRec(BSTNode* pNode, char English, string Morse)
{
	if (!pNode)
	{
		pNode = new BSTNode(English, Morse);
		return;
	}

	if (English < pNode->getEnglish())
	{
		if (!pNode->getLeft())
		{
			pNode->setLeft(new BSTNode(English, Morse));
		}
		else
		{
			insertRec(pNode->getLeft(), English, Morse);
		}
	}
	else
	{
		if (!pNode->getRight())
		{
			pNode->setRight(new BSTNode(English, Morse));
		}
		else
		{
			insertRec(pNode->getRight(), English, Morse);
		}
	}
}

void BST::insert(char English, string Morse)
{
	if (!pRoot)
	{
		pRoot = new BSTNode(English, Morse);
	}
	else
	{
		insertRec(pRoot, English, Morse);
	}
}

string BST::searchRec(BSTNode* pNode, char Searching) const
{
	if (!pNode)
	{
		return "";
	}

	if (Searching == pNode->getEnglish())
	{
		return pNode->getMorse();
	}
	else if (Searching < pNode->getEnglish())
	{
		return searchRec(pNode->getLeft(), Searching);
	}
	else
	{
		return searchRec(pNode->getRight(), Searching);
	}
}

string BST::search(char Searching) const
{
	return searchRec(pRoot, Searching);
}

void BST::printRec(BSTNode* pNode)
{
	if (!pNode)
	{
		return;
	}

	printRec(pNode->getLeft());
	cout << pNode->getEnglish() << " : " << pNode->getMorse() << endl;
	printRec(pNode->getRight());
}

void BST::print()
{
	if (isEmpty())
	{
		cout << "BST is Empty." << endl;
		return;
	}

	printRec(pRoot);
}

void BST::deleteRec(BSTNode* pNode)
{
	if (pNode)
	{
		deleteRec(pNode->getLeft());
		deleteRec(pNode->getRight());
		delete pNode;
	}
}

void BST::openFile(string& infile)
{
	ifstream DataFile(infile);

	if (!DataFile)
	{
		cout << "File Failed Opening." << endl;
		return;
	}

	char letter;
	string MorseCode;

	while (DataFile >> letter >> MorseCode)
	{
		insert(letter, MorseCode);
	}

	DataFile.close();
}

