#pragma once

#include "BST.h"
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class Conversion
{
private:

	BST morseCode;

public:

	//Constructors and Destructors
	Conversion();
	~Conversion();

	//members
	void Morse_Create(string& TableFile);
	void ConverterText(string& infile);
	void Display(string& text, string Morse);
	void MorseCodeConverter();
};

