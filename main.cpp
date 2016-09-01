#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "Commands.h"
//#include "Debug.h"
#include "CharParse.h"
#include "Decrypt.h"

using namespace std;

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
