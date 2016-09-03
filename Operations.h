#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Status.h"

#include <string>

int charToInt(char inputChar);
char intToChar(int inputInt);

std::string generateNewName(std::string currentName, Status status);

#endif
