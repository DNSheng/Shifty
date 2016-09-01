#include "Debug.h"

#include <iostream>

void DEBUGcommandCheck(bool& decrypting, bool& encrypting)												//DEBUG FUNCTION
{
	std::cout << "DECRYPTING STATUS: " << decrypting << std::endl;
	std::cout << "ENCRYPTING STATUS: " << encrypting << std::endl;
}
void DEBUGgetCommand(std::string& command, std::string& file)														//DEBUG FUNCTION
{
	std::cout << "You wanted to " << command << " the " << file << std::endl;
}
