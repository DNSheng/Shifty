#include "FileHandling.h"
#include "Operations.h"
#include "Input.h"
#include "Modifications.h"
#include "BruteForce.h"

#include <iostream>
#include <fstream>

void readFile(const std::string& file, const Status& status)
{
	std::string line, newFileName;
	int encryptionKey;

	newFileName = generateNewName(file, status);
	const char* newFileNameChar = newFileName.c_str();
	const char* fileChar = file.c_str();

	std::ifstream inputFile(fileChar);

	if(inputFile.is_open())
	{
		getEncryptionKey(encryptionKey, status);
		if((encryptionKey == 0) && (status == DECRYPTING))
		{
			startBruteForce(file);
		}
		createNewFile(newFileNameChar);				//Something over here in the future for creating custom files
		while(!inputFile.eof())
		{
			getline(inputFile, line);
			modifyLine(line, encryptionKey, newFileNameChar);
		}
		inputFile.close();
		endingMessage(status);
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

void appendStringToFile(const char* fileName, const std::string& input)
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

void endingMessage(const Status& status)
{
	if(status == ENCRYPTING)
	{
		std::cout << "Encryption is complete" << std::endl;
	}
	else
	{
		std::cout << "Decryption is complete" << std::endl;
	}
}
