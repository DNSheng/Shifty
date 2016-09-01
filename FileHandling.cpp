#include "FileHandling.h"
#include "Commands.h"
#include "Decrypt.h"
#include "CharParse.h"
#include "Conversions.h"

#include <iostream>
#include <fstream>

void readFile(std::string fileName, int encryptionKey, bool decrypting, bool encrypting)
{
	std::string line, newFileName;

	std::cout << "readFile currentFileName: " << fileName << std::endl;
	newFileName = generateNewName(fileName, encrypting);
	//std::cout << "fileName is: " << currentFileName << std::endl;
	std::cout << "The new file name is: " << newFileName << std::endl;

	const char* newFileNameChar = newFileName.c_str();

	std::ifstream myFile (fileName);									//Open file

		if(myFile.is_open())										//While open, get the key
		{
			if(decrypting)
			{
				getEncryptionKey(encryptionKey, decrypting, encrypting);
				createNewFile(newFileNameChar);
				while(!myFile.eof())
				{
					getline(myFile, line);
					beginDecryption(line, encryptionKey, decrypting, encrypting, newFileNameChar);
				}
				myFile.close();
				std::cout << "\nDecryption is complete..." << std::endl;
			}
			else if(encrypting)
			{
				getEncryptionKey(encryptionKey, decrypting, encrypting);
				createNewFile(newFileNameChar);
				while(!myFile.eof())
				{
					getline(myFile, line);
					passingCharInLine(line, encryptionKey, decrypting, encrypting, newFileNameChar);
				}
				myFile.close();
				std::cout << "\nEncryption is complete..." << std::endl;
			}
		}
		else
		{
			std::cout << "ERROR: Unable to find file: " << fileName << std::endl;
		}
}

void createNewFile(const char* fileName)
{
	std::ofstream outputFile(fileName);
	outputFile.close();
}

/*
 * NEEDS FIXING
 */
void appendToFile(const char* fileName, std::string input)
{
	//std::cout << "APPENDING: " << input << std::endl;
	std::ofstream outputFile(fileName);
	if(outputFile.is_open())
	{
		outputFile << input;
		outputFile.close();
	}
	else
	{
		std::cout << "Error: There was a problem writing to the file" << std::endl;
	}
}
