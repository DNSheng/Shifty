#include "Modifications.h"
#include "Operations.h"
#include "Crypt.h"
#include "Input.h"
#include "FileHandling.h"

#include <iostream>

char charEncryption(const int& encryptionKey, const char& fileChar)
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

	return modifiedChar;
}

void normalModifyChar(const int& encryptionKey, const char& fileChar, const char* fileWritingTo)
{

	char modifiedChar = charEncryption(encryptionKey, fileChar);
	std::string currentModifiedChar(1, modifiedChar);
	modifiedLine.append(currentModifiedChar);
}

/*
 * TEMP SOLVE: Skips newlines since successive encrypting/decrypting adds a new line
 * 			   character at the end of the file. The drawback is that formating is
 * 			   somewhat lost.
 */

void modifyLine(std::string& line, const int& encryptionKey, const char* fileWritingTo)
{
	if(line.length() != 0)
	{
		for(unsigned i = 0; i < line.length(); i++)
		{
			char fileChar = line.at(i);
			normalModifyChar(encryptionKey, fileChar, fileWritingTo);
		}

		appendStringToFile(fileWritingTo, modifiedLine);
		appendStringToFile(fileWritingTo, "\n");
		modifiedLine.clear();
	}
}

void bruteModifyLine(const std::string& bestLine, std::vector<std::string>& decryptions)
{
	//CIPHER_SIZE + 1 otherwise it misses a key
	for(int encryptionKey = 0; encryptionKey < CIPHER_SIZE + 1; encryptionKey++)
	{
		std::string currentLine;

		for(unsigned i = 0; i < bestLine.length(); i++)
		{
			char fileChar = bestLine.at(i);
			bruteModifyChar(encryptionKey, fileChar, currentLine);
		}
		decryptions.push_back(currentLine);
	}
}

void bruteModifyChar(const int& encryptionKey, const char& fileChar, std::string& currentLine)
{
	char modifiedChar = charEncryption(encryptionKey, fileChar);
	std::string currentModifiedChar(1, modifiedChar);
	currentLine.append(currentModifiedChar);
}
