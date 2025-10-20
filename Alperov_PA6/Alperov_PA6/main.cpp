#include "Conversion.h"
#include <iostream>
#include <string>

int main()
{
    string morseFile = "MorseTable.txt";
    string convertFile = "Convert.txt";

    Conversion converter;

    converter.Morse_Create(morseFile);

    converter.ConverterText(convertFile);

    return 0;
}
