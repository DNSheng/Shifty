#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Status.h"

#include <string>

int charToInt(const char& inputChar);
char intToChar(const int& inputInt);

std::string generateNewName(const std::string& currentName, const Status& status);

#endif
