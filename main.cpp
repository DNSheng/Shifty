#include <iostream>
#include <stdlib.h>
#include <fstream>

//#include "Debug.h"

#include "FileHandling.h"
#include "CommandTest.h"
#include "Conversions.h"

using namespace std;

int main()
{
	string command, file, fixedName;
	Status status;
	int encryptionKey = 0;

	initializationTEST(command, file, status);
	//DEBUGcommandCheck(decrypting, encrypting);					//DEBUG FUNCTION CALL

	fixedName = fixedFileName(file);

	readFile(fixedName, encryptionKey, status);

	main();
}
