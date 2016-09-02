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

#include "Commands.h"

#include <iostream>

void initialization(std::string& command, std::string& file, Status& status)
{
	std::cout << "COMMAND: " << command << std::endl;
	std::cout << "FILE: " << file << std::endl;
	command.clear();
	file.clear();
	std::cout << "CLEARED" << std::endl;
	std::cout << "COMMAND: " << command << std::endl;
	std::cout << "FILE: " << file << std::endl;
	getCommand(command, file, status);
	//DEBUGgetCommand(command, file);																			//DEBUG	FUNCTION CALL
	commandCheck(command, file, status);
}

void getCommand(std::string& command, std::string& file, Status& status)
{
	//command.clear();
	std::cout << "> ";
	std::cin >> command;
	std::cout << "COMMAND: " << command << std::endl;
	std::cout << "FILE: " << file << std::endl;
	if((command == "decrypt") || (command == "encrypt"))
	{
		//std::cin >> file;
		getline(std::cin, file);
		std::cout << "FILENAME FROM GETCOMMAND: " << file << std::endl;
	}
	else
	{
		exitCheck(command);
		if(isClearCommand(command))
		{
			system("cls");
			initialization(command, file, status);
		}
		else
		{
			std::cout << "Error: Unknown Command son" << std::endl;
			initialization(command, file, status);
		}
	}
}

void exitCheck(std::string& command)
{
	if(command == "exit")
	{
		exit(0);
	}
}

bool isClearCommand(std::string& command)
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

void commandCheck(std::string& command, std::string& file, Status& status)
{
	if(command == "decrypt")
	{
		//std::cout << "DECRYPTING..." << std::endl;																//DEBUG STATEMENT
		status = DECRYPTING;
	}
	else if (command == "encrypt")
	{
		//std::cout << "ENCRYPTING..." << std::endl;																//DEBUG STATEMENT
		status = ENCRYPTING;
	}
	else
	{
		std::cout << "ERROR: Unknown command" << std::endl;
		initialization(command, file, status);
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
