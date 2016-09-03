#include "Menu.h"
#include "Input.h"
#include "FileHandling.h"

using namespace std;

int main()
{
	string file;
	Status status;

	mainMenu();

	for(;;)
	{
		initialization(file, status);
		readFile(file, status);
	}

	return 0;
}
