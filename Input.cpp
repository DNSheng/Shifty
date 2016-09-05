#include "Input.h"
#include "Operations.h"
#include "Help.h"

#include <iostream>

void initialization(std::string& file, Status& status)
{
	userInput.clear();
	command.clear();
	file.clear();

	inputArrow();
	getline(std::cin, userInput);
	splitting(userInput, command, file);
	checking(command, file, status);
}

void inputArrow()
{
	std::cout << "> ";
}

void splitting(const std::string& userInput, std::string& command, std::string& file)
{
	unsigned int pointer = 0;

	splitCommand(userInput, command, pointer);
	splitFile(userInput, file, pointer);
}

void splitCommand(const std::string& userInput, std::string& command, unsigned int& pointer)
{
	std::string tempString;

	for(unsigned int i = 0; i < userInput.length(); i++)
	{
		if(userInput[i] == ' ')
		{
			tempString = userInput.substr(0, i);
			pointer = i + 1;
			command = tempString;
			break;
		}
	}

	if(tempString.empty())
	{
		command = userInput;
	}
}

void splitFile(const std::string& userInput, std::string& file, const unsigned int& pointer)
{
	if(pointer != 0)
	{
		file = userInput.substr(pointer, userInput.length() - pointer);
	}
}

void checking(const std::string& command, std::string& file, Status& status)
{
	checkCommand(command, status);
	checkRestart(file, status);
	checkFile(file, status);
	checkRestart(file, status);
}

void checkCommand(const std::string& command, Status& status)
{
	if(command.compare("exit") == 0)
	{
		exit(0);
	}
	else if(command.compare("clear") == 0)
	{
		system("cls");
		status = RESTART;
	}
	else if(command.compare("help") == 0)
	{
		helpMenu();
		status = RESTART;
	}
	else if(command.compare("encrypt") == 0)
	{
		status = ENCRYPTING;
	}
	else if(command.compare("decrypt") == 0)
	{
		status = DECRYPTING;
	}
	else
	{
		//Unknown command
		std::cout << "Error: Invalid command" << std::endl;
		status = RESTART;
	}
}

void checkFile(const std::string& file, Status& status)
{
	if(file.empty())
	{
		std::cout << "Error: No file given" << std::endl;
		status = RESTART;
		return;
	}
	else if(file.length() < 5)
	{
		std::cout << "Error: Invalid file" << std::endl;
		status = RESTART;
		return;
	}

	for(unsigned int i = 0; i < file.length(); i++)
	{
		if(file[i] == ' ')
		{
			std::cout << "Error: Too many arguments" << std::endl;
			status = RESTART;
			return;
		}
	}

	std::string fileExtension;
	fileExtension = file.substr(file.length() - 4, 4);

	if(fileExtension.compare(".txt") != 0)
	{
		std::cout << "Error: Invalid file format" << std::endl;
		status = RESTART;
	}
}

void checkRestart(std::string& file, Status& status)
{
	if(status == RESTART)
	{
		initialization(file, status);
	}
}

void getEncryptionKey(int& encryptionKey, const Status& status)
{
	int keyBuffer;

	getKeyMessage(status);

	while(!(std::cin >> keyBuffer))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Error: Invalid key, please try again" << std::endl;
		inputArrow();
	}

	std::cin.ignore();

	if(isValidKey(keyBuffer))
	{
		encryptionKey = keyBuffer;
		simplifyKey(encryptionKey, status);
	}
	else
	{
		std::cout << "Error: Invalid key, please try again" << std::endl;
		getEncryptionKey(encryptionKey, status);
	}
}

void getKeyMessage(const Status& status)
{
	if(status == ENCRYPTING)
	{
		std::cout << "Please enter an encryption key" << std::endl;
		inputArrow();
	}
	else if(status == DECRYPTING)
	{
		std::cout << "Please enter the decryption key (key used to encrypt)" << std::endl;
		std::cout << "Enter 0 to brute force" << std::endl;
		inputArrow();
	}
	else
	{
		std::cout << "Error: An unexpected error has occurred" << std::endl;
		exit(0);
	}
}

bool isValidKey(const int& encryptionKey)
{
	int absoluteValue = abs(encryptionKey);
	std::string keyString = std::to_string(absoluteValue);

	for(unsigned i = 1; i < keyString.length(); i++)
	{
		if(!isNumber(keyString[i]))
		{
			return false;
		}
	}
	return true;
}

bool isNumber(const char& inputChar)
{
	int charASCII = charToInt(inputChar);
	if((charASCII >= ASCII_ZERO) && (charASCII <= ASCII_NINE))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void simplifyKey(int& encryptionKey, const Status& status)
{
	if(status == ENCRYPTING)
	{
		if(encryptionKey < 0)
		{
			if(encryptionKey % CIPHER_SIZE == 0)
			{
				encryptionKey = 0;
			}
			else
			{
				encryptionKey = CIPHER_SIZE + (encryptionKey % CIPHER_SIZE);
			}
		}
		else
		{
			encryptionKey = encryptionKey % CIPHER_SIZE;
		}
	}
	else
	{
		if(encryptionKey < 0)
		{
			encryptionKey = -1 * (encryptionKey % CIPHER_SIZE);
		}
		else if(encryptionKey != 0)
		{
			encryptionKey = CIPHER_SIZE - (encryptionKey % CIPHER_SIZE);
		}
	}
}
