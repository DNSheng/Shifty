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

		if(fileExists(newFileNameChar))
		{
			std::cout << "Warning! " << newFileName << " already exists. Overwrite? (y/n)" << std::endl;
			if(isOverwrite())
			{
				createNewFile(newFileNameChar);
			}
			else
			{
				//Passing argument useless, as it is a const and therefore it still overwrites
				fileCreation(newFileNameChar);
				//Trivial, probably bad solution is to copy while() block below + bottom 2 statements, then add a return;
			}
		}
		else
		{
			createNewFile(newFileNameChar);
		}

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

/*
 * This function might be useless, since if we skip this step, appendStringToFile() will also create the file.
 */
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
		//Find a way to break out, back to initialization (preferably without passing file everywhere)
		//Shouldn't happen if isValidFile() checks the NEW user inputted file before it is even opened to write
		exit(0);
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

bool fileExists(const char* fileName)
{
	std::ifstream file(fileName);
	if(file.good())
	{
		file.close();
		return true;
	}
	return false;
}

void fileCreation(const char* newFileNameChar)
{
	std::string newFileName;

	newFileName = getNewFileName();
	newFileNameChar = newFileName.c_str();

	if(isValidNewFile(newFileNameChar))
	{
		createNewFile(newFileNameChar);
	}
	else
	{
		std::cout << "Error: File is invalid (wrong extention, or already exists)" << std::endl;
		std::cout << "Please try again." << std::endl;
		fileCreation(newFileNameChar);
	}
}

bool isValidNewFile(const char* fileName)
{
	//Ends in .txt
	//Doesn't already exist
	std::string fileNameString = fileName;
	if((isValidFileExt(fileNameString)) && (!fileExists(fileName)))
	{
		return true;
	}
	return false;
}
