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
	string command, file, fixedName;
	Status status;
	int encryptionKey = 0;

	initialization(command, file, status);
	//DEBUGcommandCheck(decrypting, encrypting);					//DEBUG FUNCTION CALL

	fixedName = fixedFileName(file);

	//string test = fileName;

	//cout << "FIXED FILENAME MAIN: " << test << endl;

	readFile(fixedName, encryptionKey, status);

	main();
}
