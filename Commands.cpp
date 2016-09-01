#include "Commands.h"
//#include "Debug.h"

#include <iostream>

void initialization(std::string& command, std::string& file, bool& decrypting, bool& encrypting)
{
	getCommand(command, file, decrypting, encrypting);
	//DEBUGgetCommand(command, file);																			//DEBUG	FUNCTION CALL
	commandCheck(command, file, decrypting, encrypting);
}

void commandCheck(std::string& command, std::string& file, bool& decrypting, bool& encrypting)
{
	if(command == "decrypt")
	{
		std::cout << "DECRYPTING..." << std::endl;																//DEBUG STATEMENT
		decrypting = true;
	}
	else if (command == "encrypt")
	{
		std::cout << "ENCRYPTING..." << std::endl;																//DEBUG STATEMENT
		encrypting = true;
	}
	else
	{
		std::cout << "ERROR: Unknown command." << std::endl;
		initialization(command, file, decrypting, encrypting);
	}

}

void getCommand(std::string& command, std::string& file, bool& decrypting, bool& encrypting)
{
	std::cout << "> ";
	std::cin >> command;
	exitCheck(command);
	if(isClear(command))
	{
		system("cls");
		initialization(command, file, decrypting, encrypting);
	}
	else
	{
		std::cin >> file;
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

void exitCheck(std::string& command)
{
	if(command == "exit")
	{
		exit(0);
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
	if(encryptionKey > CIPHER_SIZE)
	{
		encryptionKey -= CIPHER_SIZE;
	}
}

