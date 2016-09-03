#include "Input.h"
#include "FileHandling.h"

using namespace std;

int main()
{
	string file;
	Status status;

	for(;;)
	{
		initialization(file, status);
		readFile(file, status);
	}

	return 0;
}
