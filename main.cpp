#include <iostream>
#include <stdlib.h>
#include <fstream>
#define LOWERCASE_A_BOUND 97
#define LOWERCASE_Z_BOUND 122
#define UPPERCASE_A_BOUND 65
#define UPPERCASE_Z_BOUND 90
#define CIPHER_SIZE 26

using namespace std;

void initialization(string& command, string& file, bool& decrypting, bool& encrypting);
void getCommand(string& command, string& file, bool& decrypting, bool& encrypting);
void DEBUGgetCommand(string& command, string& file);
void commandCheck(string& command, string& file, bool& decrypting, bool& encrypting);
void DEBUGcommandCheck(bool& decrypting, bool& encrypting);
void exitCheck(string& command);
bool isClear(string& command);
void getEncryptionKey(int& encryptionKey, bool& decrypting, bool& encrypting);
int charToInt(char inputChar);
char intToChar(int inputInt);
void parseChar(int encryptionKey, char fileChar, bool& decrypting, bool& encrypting);
void passingCharInLine(string& line, int& encryptionKey, bool& decrypting, bool& encrypting);
int encryptChar(int encryptionKey, int fileCharNum, bool isUpper);
void beginDecryption(string& line, int& encryptionKey, bool& decrypting, bool& encrypting);
void decryptWithoutKey();
int decryptChar(int encryptionKey, int fileCharNum, bool isUpper);


void decryptWithoutKey()
{
	cout << "Not done yet..." << endl;
}
int decryptChar(int encryptionKey, int fileCharNum, bool isUpper)
{
	int encryptedChar, decryptionDiff;
	decryptionDiff = fileCharNum - encryptionKey;
	if(isUpper)
	{
		//Uppercase math
		if(decryptionDiff < UPPERCASE_A_BOUND)
		{
			int removalAmount = fileCharNum - UPPERCASE_A_BOUND;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = UPPERCASE_Z_BOUND + 1 - remainder;
		}
		else
		{
			encryptedChar = fileCharNum - encryptionKey;
		}
	}
	else
	{
		//Lowercase math
		if(decryptionDiff < LOWERCASE_A_BOUND)
		{
			int removalAmount = fileCharNum - LOWERCASE_A_BOUND;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = LOWERCASE_Z_BOUND + 1 - remainder;
		}
		else
		{
			encryptedChar = fileCharNum - encryptionKey;
		}
	}
	//cout << "ENCRYPTEDCHAR: " << encryptedChar << endl;													//DEBUG STATEMENT
	return encryptedChar;
}
void beginDecryption(string& line, int& encryptionKey, bool& decrypting, bool& encrypting)
{
	if(encryptionKey == 0)
	{
		decryptWithoutKey();
	}
	else
	{
		passingCharInLine(line, encryptionKey, decrypting, encrypting);
	}
}
int encryptChar(int encryptionKey, int fileCharNum, bool isUpper)
{
	int encryptedChar, encryptionSum;
	encryptionSum = fileCharNum + encryptionKey;
	if(isUpper)
	{
		//Uppercase math
		if(encryptionSum > UPPERCASE_Z_BOUND)
		{
			int removalAmount = UPPERCASE_Z_BOUND - fileCharNum;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = UPPERCASE_A_BOUND - 1 + remainder;
		}
		else
		{
			encryptedChar = fileCharNum + encryptionKey;
		}
	}
	else
	{
		//Lowercase math
		if(encryptionSum > LOWERCASE_Z_BOUND)
		{
			int removalAmount = LOWERCASE_Z_BOUND - fileCharNum;
			int remainder = encryptionKey - removalAmount;
			encryptedChar = LOWERCASE_A_BOUND - 1 + remainder;
		}
		else
		{
			encryptedChar = fileCharNum + encryptionKey;
		}
	}
	return encryptedChar;
}
void parseChar(int encryptionKey, char fileChar, bool& decrypting, bool& encrypting)
{
	int fileCharNumber = charToInt(fileChar);
	int modifiedInteger = fileCharNumber;
	//cout << "FILE CHAR NUMBER: " << fileCharNumber << endl;											//DEBUG STATEMENT
	if((fileCharNumber >= LOWERCASE_A_BOUND) & (fileCharNumber <= LOWERCASE_Z_BOUND))
	{
		//Lowercase
		if(encrypting)
		{
			modifiedInteger = encryptChar(encryptionKey, fileCharNumber, false);
		}
		else if(decrypting)
		{
			modifiedInteger = decryptChar(encryptionKey, fileCharNumber, false);
		}
	}
	else if((fileCharNumber >= UPPERCASE_A_BOUND) & (fileCharNumber <= UPPERCASE_Z_BOUND))
	{
		//Uppercase
		if(encrypting)
		{
			modifiedInteger = encryptChar(encryptionKey, fileCharNumber, true);
		}
		else if(decrypting)
		{
			modifiedInteger = decryptChar(encryptionKey, fileCharNumber, true);
		}
	}
	else
	{
		//Symbol or number; do not modify
	}
	//cout << encryptedInteger;																			//DEBUG STATEMENT
	char encryptedChar = intToChar(modifiedInteger);
	cout << encryptedChar;
}
void passingCharInLine(string& line, int& encryptionKey, bool& decrypting, bool& encrypting)
{
	char fileChar;
	//cout << "ENCRYPTIONKEY: " << encryptionKey << endl;												//DEBUG STATEMENT
	for(unsigned i = 0; i < line.length(); i++)
	{
		fileChar = line.at(i);
		parseChar(encryptionKey, fileChar, decrypting, encrypting);
	}
}
char intToChar(int inputInt)
{
	char outputChar = char(inputInt);
	return outputChar;
}
int charToInt(char inputChar)
{
	int outputNumber = int(inputChar);
	return outputNumber;
}
void getEncryptionKey(int& encryptionKey, bool& decrypting, bool& encrypting)
{
	if(decrypting)
	{
		cout << "Enter the decrypting key (to solve, enter 0):" << endl << "> ";
	}
	else if(encrypting)
	{
		cout << "Enter the encryption key: " << endl << "> ";
	}
	cin >> encryptionKey;
	if(encryptionKey > CIPHER_SIZE)
	{
		encryptionKey -= CIPHER_SIZE;
	}
}
bool isClear(string& command)
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
void exitCheck(string& command)
{
	if(command == "exit")
	{
		exit(0);
	}
}
void DEBUGcommandCheck(bool& decrypting, bool& encrypting)												//DEBUG FUNCTION
{
	cout << "DECRYPTING STATUS: " << decrypting << endl;
	cout << "ENCRYPTING STATUS: " << encrypting << endl;
}
void commandCheck(string& command, string& file, bool& decrypting, bool& encrypting)
{
	if(command == "decrypt")
	{
		cout << "DECRYPTING..." << endl;																//DEBUG STATEMENT
		decrypting = true;
	}
	else if (command == "encrypt")
	{
		cout << "ENCRYPTING..." << endl;																//DEBUG STATEMENT
		encrypting = true;
	}
	else
	{
		cout << "ERROR: Unknown command." << endl;
		initialization(command, file, decrypting, encrypting);
	}

}
void DEBUGgetCommand(string& command, string& file)														//DEBUG FUNCTION
{
	cout << "You wanted to " << command << " the " << file << endl;
}
void getCommand(string& command, string& file, bool& decrypting, bool& encrypting)
{
	cout << "> ";
	cin >> command;
	exitCheck(command);
	if(isClear(command))
	{
		system("cls");
		initialization(command, file, decrypting, encrypting);
	}
	else
	{
		cin >> file;
	}
}
void initialization(string& command, string& file, bool& decrypting, bool& encrypting)
{
	getCommand(command, file, decrypting, encrypting);
	//DEBUGgetCommand(command, file);																	//DEBUG	FUNCTION CALL
	commandCheck(command, file, decrypting, encrypting);
}
int main()
{
	string command, file, line;
	bool decrypting, encrypting;
	int encryptionKey;

	initialization(command, file, decrypting, encrypting);
	//DEBUGcommandCheck(decrypting, encrypting);														//DEBUG FUNCTION CALL

	const char *fileName = file.c_str();							//Convert string to char*

	ifstream myFile (fileName);										//Open file

	if(myFile.is_open())											//While open, get the key
	{
		if(decrypting)
		{
			getEncryptionKey(encryptionKey, decrypting, encrypting);
			while(!myFile.eof())
			{
				getline(myFile, line);
				beginDecryption(line, encryptionKey, decrypting, encrypting);
			}
			myFile.close();
			cout << "\n";
		}
		else if(encrypting)
		{
			getEncryptionKey(encryptionKey, decrypting, encrypting);
			while(!myFile.eof())
			{
				getline(myFile, line);
				passingCharInLine(line, encryptionKey, decrypting, encrypting);
			}
			myFile.close();
			cout << "\n";
		}
	}
	else
	{
		cout << "ERROR: Unable to find file." << endl;
		main();
	}

	main();
}
