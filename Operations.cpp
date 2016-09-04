#include "Operations.h"

int charToInt(const char& inputChar)
{
	return (int)inputChar;
}

char intToChar(const int& inputInt)
{
	return (char)inputInt;
}

std::string generateNewName(const std::string& currentName, const Status& status)
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
