/*
 * This is what handles and checks the user input before it is sent to any other functions.
 * This recieves:
 * 	- Command
 * 	- Name/location of file
 * 	- Encryption/Decryption Key
 * This checks:
 * 	- Commands
 * 		- exit
 * 		- quit
 * 		- encrypt
 * 		- decrypt
 *
 * Fix the getCommand(). If entering an invalid command with a file, it gives an error twice.
 * First, it uses the invalid command as a command, then it loops again and uses the file name
 * as a command.
 */

#include "Input.h"

#include <iostream>

void initialization(std::string& command, std::string& file, Status& status)
{
	command.clear();
	file.clear();
	getUserInput(command, file);
	userInputCheck(command, file, status);
}

void getUserInput(std::string& command, std::string& file)
{
	std::string userInput;
	std::cout << "> ";
	getline(std::cin, userInput);
	interpretInput(userInput, command, file);
}

void interpretInput(std::string userInput, std::string& command, std::string& file)
{
	//Split userInput into the command and file, ignoring any thing after the file
	unsigned int fileStartingPoint;
	splitCommand(userInput, command, fileStartingPoint);
	splitFile(userInput, file, fileStartingPoint);
}

void splitCommand(std::string userInput, std::string& command, unsigned int& fileStartingPoint)
{
	std::string tempString;
	for(unsigned int i = 0; i < userInput.length(); i++)
	{
		if(userInput[i] == ' ')
		{
			tempString = userInput.substr(0, i);
			fileStartingPoint = i + 1;
			command = tempString;
			break;
		}
	}
	if(tempString.empty())
	{
		command = userInput;
	}
}

void splitFile(std::string userInput, std::string& file, unsigned int startingPoint)
{
	//If startingPoint == 0, there was no space/file given by user, only a command.
	//Therefore, the file string in main.cpp will remain empty.
	if(startingPoint != 0)
	{
		file = userInput.substr(startingPoint, userInput.length() - startingPoint);
	}
}

void splitFileAlternate(std::string userInput, std::string& file, unsigned int startingPoint)
{
	/*
	 * This works, but when checking if the file is valid, an error given by checkFile()
	 * is ambiguous. This scans through the remaining userInput, and ignores improper
	 * format, i.e. something like "encrypt file.txt test" where there is more text.
	 * Something like this should throw an error as it is improper format. If the
	 * userInput has no file section (i.e. SPACE, then filename.txt), then the file
	 * variable held by main.cpp is left empty.
	 *
	 * checkFile() with this function would then only be checking if the file
	 * (i.e. second argument) has a correct format of ".txt", not if the overall input
	 * is correct. Therefore cases such as an no file included or extra arguments are
	 * ignored, and it opts for a generic error. The better version would output to the
	 * screen what went wrong (ERROR: No file included, ERROR: Too many arguments/Wrong
	 * format).
	 */
	std::string tempString;
	for(unsigned int i = startingPoint; i < userInput.length(); i++)
	{
		if(userInput[i] == ' ')
		{
			tempString = userInput.substr(startingPoint, i - startingPoint);
			file = tempString;
			break;
		}
	}
	if(tempString.empty())
	{
		file = userInput.substr(startingPoint, userInput.length() - startingPoint);
	}
}

void userInputCheck(std::string& command, std::string& file, Status& status)
{
	checkCommand(command, file, status);
	checkFile(command, file, status);
}

void checkCommand(std::string& command, std::string& file, Status& status)
{
	exitCheck(command);
	if(isClearCommand(command))
	{
		system("cls");
		initialization(command, file, status);
	}
	else if(command == "encrypt")
	{
		status = ENCRYPTING;
	}
	else if(command == "decrypt")
	{
		status = DECRYPTING;
	}
	else
	{
		std::cout << "ERROR: Unknown command..." << std::endl;
		initialization(command, file, status);
	}
}

void checkFile(std::string& command, std::string& file, Status& status)
{
	if(file.empty())
	{
		std::cout << "Error: No file given" << std::endl;
		initialization(command, file, status);
	}

	std::string fileExtension = file.substr(file.length() - 4, 4);

	if(fileExtension != ".txt")
	{
		//Do for-loop to check for a space. If there is, too many arguments. If not, wrong file format.
		for(unsigned int i = 0; i < file.length(); i++)
		{
			if(file[i] == ' ')
			{
				std::cout << "Error: Too many arguments" << std::endl;
				initialization(command, file, status);
			}
		}
		std::cout << "Error: Invalid file format" << std::endl;
		initialization(command, file, status);
	}
}

void checkFileAlternate(std::string& command, std::string& file, Status& status)
{
	std::string fileExtension;
	fileExtension = file.substr(file.length() - 4, 4);
	if(fileExtension != ".txt")
	{
		std::cout << "Error: Invalid file format..." << std::endl;
		initialization(command, file, status);
	}
}

void exitCheck(std::string command)
{
	if(command == "exit")
	{
		exit(0);
	}
}

bool isClearCommand(std::string command)
{
	if(command == "cls")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void getEncryptionKey(int& encryptionKey, Status& status)
{
	if(status == DECRYPTING)
	{
		std::cout << "Enter the decrypting key (to solve, enter 0):" << std::endl << "> ";
	}
	else if(status == ENCRYPTING)
	{
		std::cout << "Enter the encryption key: " << std::endl << "> ";
	}
	std::cin >> encryptionKey;
	if((encryptionKey > CIPHER_SIZE) | (encryptionKey < 0))
	{
		encryptionKey = (encryptionKey % CIPHER_SIZE);
	}
}
