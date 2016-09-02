#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "Status.h"

#include <fstream>

void readFile(std::string fileName, int encryptionKey, Status status);
void createNewFile(const char* fileName);
void appendToFile(const char* fileName, std::string input);

#endif
