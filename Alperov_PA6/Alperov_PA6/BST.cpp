#include "BST.h"



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

void BST::deleteRec(BSTNode* pNode)
{
	if (pNode)
	{
		deleteRec(pNode->getLeft());
		deleteRec(pNode->getRight());
		delete pNode;
	}
}

BST::BST()
{
	pRoot = nullptr;
}

BST::~BST()
{
	deleteRec(pRoot);
	pRoot = nullptr;
	cout << "Destructor Activated" << endl; // Remember to delete this.
}

bool BST::isEmpty() const
{
	return pRoot == nullptr;
}

void BST::insert(char English, string Morse)
{
	if (!pRoot)
	{
		pRoot = new BSTNode(English, Morse);
		return;

	}

	BSTNode* pCur = pRoot;

	while (true)
	{
		if (English < pCur->getEnglish())
		{
			if (!pCur->getLeft())
			{
				pCur->setLeft(new BSTNode(English, Morse));
				break;
			}
			pCur = pCur->getLeft();
		}
		else
		{
				if (!pCur->getRight())
				{
					pCur->setRight(new BSTNode(English, Morse));
					break;
				}
				pCur = pCur->getRight();
		}
	}
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

string BST::search(char Searching) const
{
	BSTNode* pCur = pRoot;

	while (pCur != nullptr)
	{
		if (Searching == pCur->getEnglish())
		{
			return pCur->getMorse();
		}
		else if (Searching < pCur->getEnglish())
		{
			pCur = pCur->getLeft();
		}
		else
		{
			pCur = pCur->getRight();
		}
	}
	return "";
}

void BST::openFile(string& infile)
{
	char letter;
	string MorseCode;
	ifstream DataFile(infile);
	
	
	if (!DataFile)
	{
		cout << "File Failed Opening." << endl;
		return;
	}

	while (DataFile >> letter >> MorseCode)
	{
		insert(letter, MorseCode);
	}
	
	DataFile.close();
}

