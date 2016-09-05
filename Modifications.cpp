#include "Modifications.h"
#include "Operations.h"
#include "Crypt.h"
#include "FileHandling.h"

#include <iostream>

void modifyChar(const int& encryptionKey, const char& fileChar, const char* fileWritingTo)
{
	int fileCharNumber = charToInt(fileChar);
	int modifiedInteger;

	if((fileCharNumber >= LOWERCASE_A_BOUND) & (fileCharNumber <= LOWERCASE_Z_BOUND))
	{
		//Lowercase
		modifiedInteger = cryptChar(encryptionKey, fileCharNumber, false);
	}
	else if((fileCharNumber >= UPPERCASE_A_BOUND) & (fileCharNumber <= UPPERCASE_Z_BOUND))
	{
		//Uppercase
		modifiedInteger = cryptChar(encryptionKey, fileCharNumber, true);
	}
	else
	{
		//Symbol or number; do not modify
		modifiedInteger = fileCharNumber;
	}
	char modifiedChar = intToChar(modifiedInteger);

	std::string currentModifiedChar(1, modifiedChar);
	modifiedLine.append(currentModifiedChar);
}

void modifyLine(std::string& line, const int& encryptionKey, const char* fileWritingTo)
{
	char fileChar;
	if(line.length() < 1)
	{
		appendStringToFile(fileWritingTo, "\n");
	}
	else
	{
		for(unsigned i = 0; i < line.length(); i++)
		{
			fileChar = line.at(i);
			modifyChar(encryptionKey, fileChar, fileWritingTo);
		}

		appendStringToFile(fileWritingTo, modifiedLine);
		appendStringToFile(fileWritingTo, "\n");
		modifiedLine.clear();
	}
}
