#include "Conversion.h"

Conversion::Conversion() {}

Conversion::~Conversion()
{
	//cout << "Destructor Activated" << endl;
}

void Conversion::Morse_Create(string& TableFile)
{
	ifstream Convertfile(TableFile);

	if (!Convertfile)
	{
		cout << "Failed to open Morse table file." << endl;
		return;
	}

	char letter;
	string code;
	while (Convertfile >> letter >> code)
	{
		morseCode.insert(letter, code);
	}

	Convertfile.close();
}

void Conversion::ConverterText(string& infile)
{
	ifstream Morsefile(infile);

	if (!Morsefile)
	{
		cout << "Failed to open input file." << endl;
		return;
	}

	string line;
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

				string mCode = morseCode.search(character);
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
