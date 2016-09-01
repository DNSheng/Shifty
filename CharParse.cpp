#include "CharParse.h"
#include "Decrypt.h"
#include "Encrypt.h"
#include "Conversions.h"
#include "FileHandling.h"

#include <iostream>

void parseChar(int encryptionKey, char fileChar, bool& decrypting, bool& encrypting, const char* fileWritingTo)
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

	//WRITE CHAR TO FILE HERE -----------------------------------------------------
	std::string currentEncryptedChar(1, encryptedChar);
	parseCharFinalResult.append(currentEncryptedChar);
	currentEncryptedChar.clear();
	std::cout << encryptedChar;																			//DEBUG, OUTPUTS TO SCREEN
}
void passingCharInLine(std::string& line, int& encryptionKey, bool& decrypting, bool& encrypting, const char* fileWritingTo)
{
	char fileChar;
	//cout << "ENCRYPTIONKEY: " << encryptionKey << endl;												//DEBUG STATEMENT
	unsigned i;
	//std::cout << "fileName at passingCharInLine: " << fileWritingTo << std::endl;
	for(i = 0; i < line.length(); i++)
	{
		fileChar = line.at(i);
		parseChar(encryptionKey, fileChar, decrypting, encrypting, fileWritingTo);
	}
	//std::cout << std::endl;
	//std::cout << parseCharFinalResult << std::endl;
	appendToFile(fileWritingTo, parseCharFinalResult);
	//parseCharFinalResult.clear();
	//appendToFile(fileWritingTo, "\n");
}
