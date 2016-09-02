#include "Conversions.h"

#include <iostream>

char intToChar(int inputInt)
{
	char outputChar = char(inputInt);
	return outputChar;
}

int charToInt(char inputChar)
{
	int outputNumber = int(inputChar);
	return outputNumber;
}

std::string generateNewName(std::string currentName, Status status)
{
	int currentNameSize = currentName.length() - 4;					//Subtract the ".txt" part
	std::string newName = currentName.substr(0, currentNameSize);
	if(status == ENCRYPTING)
	{
		newName.append("_encrypted.txt");
	}
	else
	{
		newName.append("_decrypted.txt");
	}
	return newName;
}
