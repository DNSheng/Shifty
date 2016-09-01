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
//#include "Debug.h"

#include <iostream>

void initialization(std::string& command, std::string& file, bool& decrypting, bool& encrypting)
{
	//command.clear();
	//file.clear();
	getCommand(command, file, decrypting, encrypting);
	//DEBUGgetCommand(command, file);																			//DEBUG	FUNCTION CALL
	commandCheck(command, file, decrypting, encrypting);
}

void getCommand(std::string& command, std::string& file, bool& decrypting, bool& encrypting)
{
	//command.clear();
	std::cout << "> ";
	std::cin >> command;
	if((command == "decrypt") || (command == "encrypt"))
	{
		//std::cin >> file;
		getline(std::cin, file);
		std::cout << "FILENAME FROM GETCOMMAND: " << file << std::endl;
	}
	else
	{
		exitCheck(command);
		if(isClear(command))
		{
			system("cls");
			initialization(command, file, decrypting, encrypting);
		}
		else
		{
			std::cout << "Error: Unknown Command son" << std::endl;
			initialization(command, file, decrypting, encrypting);
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

bool isClear(std::string& command)
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

void commandCheck(std::string& command, std::string& file, bool& decrypting, bool& encrypting)
{
	if(command == "decrypt")
	{
		//std::cout << "DECRYPTING..." << std::endl;																//DEBUG STATEMENT
		decrypting = true;
	}
	else if (command == "encrypt")
	{
		//std::cout << "ENCRYPTING..." << std::endl;																//DEBUG STATEMENT
		encrypting = true;
	}
	else
	{
		std::cout << "ERROR: Unknown command" << std::endl;
		initialization(command, file, decrypting, encrypting);
	}

}

void getEncryptionKey(int& encryptionKey, bool& decrypting, bool& encrypting)
{
	if(decrypting)
	{
		std::cout << "Enter the decrypting key (to solve, enter 0):" << std::endl << "> ";
	}
	else if(encrypting)
	{
		std::cout << "Enter the encryption key: " << std::endl << "> ";
	}
	std::cin >> encryptionKey;
	if((encryptionKey > CIPHER_SIZE) | (encryptionKey < 0))
	{
		encryptionKey = (encryptionKey % CIPHER_SIZE);
	}
}
