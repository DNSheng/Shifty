#include "CharParse.h"
#include "Decrypt.h"
#include "Encrypt.h"
#include "Conversions.h"

#include <iostream>

void parseChar(int encryptionKey, char fileChar, bool& decrypting, bool& encrypting)
{
	int fileCharNumber = charToInt(fileChar);
	int modifiedInteger = fileCharNumber;
	//cout << "FILE CHAR NUMBER: " << fileCharNumber << endl;											//DEBUG STATEMENT
	if((fileCharNumber >= LOWERCASE_A_BOUND) & (fileCharNumber <= LOWERCASE_Z_BOUND))
	{
		//Lowercase
		if(encrypting)
		{
			modifiedInteger = encryptChar(encryptionKey, fileCharNumber, false);
		}
		else if(decrypting)
		{
			modifiedInteger = decryptChar(encryptionKey, fileCharNumber, false);
		}
	}
	else if((fileCharNumber >= UPPERCASE_A_BOUND) & (fileCharNumber <= UPPERCASE_Z_BOUND))
	{
		//Uppercase
		if(encrypting)
		{
			modifiedInteger = encryptChar(encryptionKey, fileCharNumber, true);
		}
		else if(decrypting)
		{
			modifiedInteger = decryptChar(encryptionKey, fileCharNumber, true);
		}
	}
	else
	{
		//Symbol or number; do not modify
	}
	//cout << encryptedInteger;																			//DEBUG STATEMENT
	char encryptedChar = intToChar(modifiedInteger);
	std::cout << encryptedChar;
}
void passingCharInLine(std::string& line, int& encryptionKey, bool& decrypting, bool& encrypting)
{
	char fileChar;
	//cout << "ENCRYPTIONKEY: " << encryptionKey << endl;												//DEBUG STATEMENT
	unsigned i;
	for(i = 0; i < line.length(); i++)
	{
		fileChar = line.at(i);
		parseChar(encryptionKey, fileChar, decrypting, encrypting);
	}
}
