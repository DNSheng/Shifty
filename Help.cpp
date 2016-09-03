#include "Help.h"
#include "Input.h"

#include <iostream>

void helpMenu()
{
	system("cls");
	std::cout << "Help menu:" << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << "Encryption/decryption is done by entering in the following format:\n" << std::endl;
	std::cout << "[COMMAND] [FILE LOCATION]\n" << std::endl;
	std::cout << "Valid [COMMAND]:" << std:: endl;
	std::cout << "\t+ encrypt\t\tEncrypts the file\n\t+ decrypt\t\tDecrypts the file\n\t+ help\t\t\t";
	std::cout << "Opens the help menu\n\t+ clear\t\t\tClears the screen\n\t+ exit\t\t\tExits the program" << std::endl;
	std::cout << "\nFiles must be of format \".txt\"" << std::endl;
	std::cout << "\nEncryption/decryption key prompt accepts any valid integer." << std::endl;
	std::cout << "\nThe encrypted/decrypted file is created in the same directory as the"<< std::endl;
	std::cout << "given file and is named depending on the operation done:" << std::endl;
	std::cout << "\n[FILE LOCATION]_encrypted.txt    or    [FILE LOCATION]_decrypted.txt" << std::endl;
	std::cout << "\nIf a file of such name already exists, its contents are overwritten." << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
}
