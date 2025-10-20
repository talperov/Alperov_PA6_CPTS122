/*
Name: Anthony Alperov
Date Started: 10/18/25
Assignment: Goal of this assignment to understand BST aka Binary Search Trees better and gain the ability to
use it during this Programming Assignment 6 which the goal is to look at a given text and provide
a morse code translation of it. Overall the assingment should be fairly simple but might face some
debugging issues.
*/
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
