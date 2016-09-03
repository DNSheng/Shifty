#include "Modifications.h"
#include "Operations.h"
#include "Encrypt.h"
#include "Decrypt.h"
#include "FileHandling.h"

#include <iostream>

void modifyChar(int encryptionKey, char fileChar, Status status, const char* fileWritingTo)
{
	int fileCharNumber = charToInt(fileChar);
	int modifiedInteger;

	if((fileCharNumber >= LOWERCASE_A_BOUND) & (fileCharNumber <= LOWERCASE_Z_BOUND))
	{
		//Lowercase
		if(status == ENCRYPTING)
		{
			modifiedInteger = encryptChar(encryptionKey, fileCharNumber, false);
		}
		else if(status == DECRYPTING)
		{
			modifiedInteger = decryptChar(encryptionKey, fileCharNumber, false);
		}
	}
	else if((fileCharNumber >= UPPERCASE_A_BOUND) & (fileCharNumber <= UPPERCASE_Z_BOUND))
	{
		//Uppercase
		if(status == ENCRYPTING)
		{
			modifiedInteger = encryptChar(encryptionKey, fileCharNumber, true);
		}
		else if(status == DECRYPTING)
		{
			modifiedInteger = decryptChar(encryptionKey, fileCharNumber, true);
		}
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

void modifyLine(std::string& line, int encryptionKey, Status status, const char* fileWritingTo)
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
			modifyChar(encryptionKey, fileChar, status, fileWritingTo);
		}

		appendStringToFile(fileWritingTo, modifiedLine);
		appendStringToFile(fileWritingTo, "\n");
		modifiedLine.clear();
	}
}
