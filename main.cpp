#include "Menu.h"
#include "Input.h"
#include "FileHandling.h"

int main()
{
	std::string file;
	Status status;

	mainMenu();

	for(;;)
	{
		initialization(file, status);
		readFile(file, status);
	}

	return 0;
}
