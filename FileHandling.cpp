#include "FileHandling.h"
#include "Commands.h"
#include "Decrypt.h"
#include "CharParse.h"

#include <iostream>
#include <fstream>

void ReadFile(const char* fileName, int encryptionKey, bool decrypting, bool encrypting)
{
	std::string line;
	std::ifstream myFile (fileName);								//Open file

		if(myFile.is_open())										//While open, get the key
		{
			if(decrypting)
			{
				getEncryptionKey(encryptionKey, decrypting, encrypting);
				while(!myFile.eof())
				{
					getline(myFile, line);
					beginDecryption(line, encryptionKey, decrypting, encrypting);
				}
				myFile.close();
				std::cout << "\n";
			}
			else if(encrypting)
			{
				getEncryptionKey(encryptionKey, decrypting, encrypting);
				while(!myFile.eof())
				{
					getline(myFile, line);
					passingCharInLine(line, encryptionKey, decrypting, encrypting);
				}
				myFile.close();
				std::cout << "\n";
			}
		}
		else
		{
			std::cout << "ERROR: Unable to find file." << std::endl;
		}
}
