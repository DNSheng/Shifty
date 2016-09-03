#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "Status.h"

#include <string>

void readFile(std::string file, Status status);
void createNewFile(const char* newFileName);
void appendStringToFile(const char* fileName, std::string input);

#endif
