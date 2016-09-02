#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "Status.h"

#include <string>

int charToInt(char inputChar);
char intToChar(int inputInt);

std::string fixedFileName(std::string fileName);

std::string generateNewName(std::string currentName, Status status);

#endif
