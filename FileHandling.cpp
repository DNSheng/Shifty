#include "FileHandling.h"
#include "Operations.h"
#include "Input.h"
#include "Modifications.h"
#include "Decrypt.h"

#include <iostream>
#include <fstream>

void readFile(std::string file, Status status)
{
	std::string line, newFileName;
	int encryptionKey;

	newFileName = generateNewName(file, status);
	const char* newFileNameChar = newFileName.c_str();
	const char* fileChar = file.c_str();

	std::ifstream inputFile(fileChar);
	if(inputFile.is_open())
	{
		if(status == ENCRYPTING)
		{
			getEncryptionKey(encryptionKey, status);
			createNewFile(newFileNameChar);
			while(!inputFile.eof())
			{
				getline(inputFile, line);
				modifyLine(line, encryptionKey, status, newFileNameChar);
			}
			inputFile.close();
			std::cout << "Encryption is complete" << std::endl;
		}
		else if(status == DECRYPTING)
		{
			getEncryptionKey(encryptionKey, status);
			createNewFile(newFileNameChar);
			while(!inputFile.eof())
			{
				getline(inputFile, line);
				beginDecryption(line, encryptionKey, status, newFileNameChar);
			}
			inputFile.close();
			std::cout << "Decryption is complete" << std::endl;
		}
		else
		{
			std::cout << "Error: An unexpected error has occurred" << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "Error: Unable to find file: " << file << std::endl;
	}
}

void createNewFile(const char* newFileName)
{
	std::ofstream newFile(newFileName);
	newFile.close();
}

void appendStringToFile(const char* fileName, std::string input)
{
	std::ofstream newFile(fileName, std::ios::out | std::ios::app);
	if(newFile.is_open())
	{
		newFile << input;
		newFile.close();
	}
	else
	{
		std::cout << "Error: There was a problem writing to the file" << std::endl;
	}

}
