#include "Conversion.h"

Conversion::Conversion() {}

Conversion::~Conversion()
{
	//cout << "Destructor Activated" << endl;
}

void Conversion::Morse_Create(string& TableFile)
{
	char letter;
	string code;

	ifstream Convertfile(TableFile);

	if (!Convertfile)
	{
		cout << "Failed to open Morse table file." << endl;
		return;
	}

	
	while (Convertfile >> letter >> code)
	{
		morseCode.insert(letter, code);
	}

	Convertfile.close();
}

void Conversion::ConverterText(string& infile)
{
	ifstream Morsefile(infile);
	string line;
	string mCode;

	if (!Morsefile)
	{
		cout << "Failed to open input file." << endl;
		return;
	}


	while (getline(Morsefile, line))
	{
		string morseLine;
		for (char character : line)
		{
			if (character != ' ')
			{
				if (character >= 'a' && character <= 'z')
				{
					character = character - 'a' + 'A';
				}

				 mCode = morseCode.search(character);
				if (!mCode.empty())
				{
					morseLine += mCode + " ";
				}
				else
				{
					morseLine += "N/A ";
				}
			}
			else
			{
				morseLine += "  ";
			}
		}

		Display(line, morseLine);
	}

	Morsefile.close();
}

void Conversion::Display(string& text, string Morse)
{
	cout << "Written Code: " << text << endl;
	cout << "Morse Code:   " << Morse << endl;
}

void Conversion::MorseCodeConverter()
{
	string morseFile = "MorseTable.txt";

	string convertFile = "Convert.txt";

	Conversion converter;

	converter.Morse_Create(morseFile);

	converter.ConverterText(convertFile);
}
