#include "Encrypt.h"
#include "CharParse.h"

int encryptChar(int encryptionKey, int fileCharNum, bool isUpper)
{
	int encryptedChar, encryptionSum;
	encryptionSum = fileCharNum + encryptionKey;
	if(isUpper)
	{
		//Uppercase math
		if(encryptionSum > UPPERCASE_Z_BOUND)
		{
			int removalAmount = UPPERCASE_Z_BOUND - fileCharNum;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = UPPERCASE_A_BOUND - 1 + remainder;
		}
		else
		{
			encryptedChar = fileCharNum + encryptionKey;
		}
	}
	else
	{
		//Lowercase math
		if(encryptionSum > LOWERCASE_Z_BOUND)
		{
			int removalAmount = LOWERCASE_Z_BOUND - fileCharNum;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = LOWERCASE_A_BOUND - 1 + remainder;
		}
		else
		{
			encryptedChar = fileCharNum + encryptionKey;
		}
	}
	return encryptedChar;
}
