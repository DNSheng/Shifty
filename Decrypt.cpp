#include "Decrypt.h"
#include "CharParse.h"

#include <iostream>

void decryptWithoutKey()
{
	std::cout << "Not done yet..." << std::endl;
}
int decryptChar(int encryptionKey, int fileCharNum, bool isUpper)
{
	int encryptedChar, decryptionDiff;
	decryptionDiff = fileCharNum - encryptionKey;
	if(isUpper)
	{
		//Uppercase math
		if(decryptionDiff < UPPERCASE_A_BOUND)
		{
			int removalAmount = fileCharNum - UPPERCASE_A_BOUND;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = UPPERCASE_Z_BOUND + 1 - remainder;
		}
		else
		{
			encryptedChar = fileCharNum - encryptionKey;
		}
	}
	else
	{
		//Lowercase math
		if(decryptionDiff < LOWERCASE_A_BOUND)
		{
			int removalAmount = fileCharNum - LOWERCASE_A_BOUND;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = LOWERCASE_Z_BOUND + 1 - remainder;
		}
		else
		{
			encryptedChar = fileCharNum - encryptionKey;
		}
	}
	//cout << "ENCRYPTEDCHAR: " << encryptedChar << endl;													//DEBUG STATEMENT
	return encryptedChar;
}
void beginDecryption(std::string& line, int& encryptionKey, Status status, const char* fileWritingTo)
{
	if(encryptionKey == 0)
	{
		decryptWithoutKey();
	}
	else
	{
		passingCharInLine(line, encryptionKey, status, fileWritingTo);
	}
}
