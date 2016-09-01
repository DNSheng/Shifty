#include <iostream>
#include <stdlib.h>
#include <fstream>

//#include "Debug.h"

#include "FileHandling.h"
#include "Commands.h"
#include "Conversions.h"

using namespace std;

int main()
{
	string command, file;
	bool decrypting, encrypting;
	int encryptionKey = 0;

	initialization(command, file, decrypting, encrypting);
	//DEBUGcommandCheck(decrypting, encrypting);					//DEBUG FUNCTION CALL

	const char *fileName = fixedFileName(file).c_str();				//Convert string to char*

	//string test = fileName;

	//cout << "FIXED FILENAME MAIN: " << test << endl;

	readFile(fileName, encryptionKey, decrypting, encrypting);

	main();
}
