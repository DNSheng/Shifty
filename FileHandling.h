#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "Status.h"

#include <string>

void readFile(const std::string& file, const Status& status);
void createNewFile(const char* newFileName);
void appendStringToFile(const char* fileName, const std::string& input);
void endingMessage(const Status& status);

#endif
