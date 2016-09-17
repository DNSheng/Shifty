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
			inputFile.close();
			startBruteForce(file);
			return;
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
				std::string customFileName;
				customFileName = getNewFileName();
				const char* customFileNameChar = customFileName.c_str();

				while(!inputFile.eof())
				{
					getline(inputFile, line);
					modifyLine(line, encryptionKey, customFileNameChar);
				}
				inputFile.close();
				endingMessage(status);
				return;
			}
		}
		while(!inputFile.eof())
		{
			getline(inputFile, line);
			std::cout << "LINE IS: |" << line << "|" << std::endl;
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

bool isValidFileName(const std::string& fileName)
{
	//Ends in .txt
	//Doesn't already exist
	const char* fileNameChar = fileName.c_str();
	if(isValidFileExt(fileName))
	{
		if(!fileExists(fileNameChar))
		{
			return true;
		}
		else
		{
			std::cout << "Error: File already exists" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Error: Invalid file extension" << std::endl;
		return false;
	}
}

void readForGather(const std::string& file, std::vector<std::string>& lineVector)
{
	const char* fileName = file.c_str();

	std::string currentLine;

	std::ifstream fileStream(fileName);

	if(fileStream.is_open())
	{
		while(!fileStream.eof())
		{
			getline(fileStream, currentLine);
			gatherLine(currentLine, lineVector);
		}
		fileStream.close();
	}
	else
	{
		std::cout << "Error: Unable to find file: " << file << std::endl;
	}
}
