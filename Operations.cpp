#include "Operations.h"

int charToInt(char inputChar)
{
	return (int)inputChar;
}

char intToChar(int inputInt)
{
	return (char)inputInt;
}

std::string generateNewName(std::string currentName, Status status)
{
	int currentNameSize = currentName.length() - 4;					//Removing ".txt"
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
