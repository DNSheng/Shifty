#include "Input.h"
#include "FileHandling.h"

using namespace std;

int main()
{
	string command, file;
	Status status;
	int encryptionKey = 0;

	initialization(command, file, status);
	readFile(file, encryptionKey, status);

	main();
}
