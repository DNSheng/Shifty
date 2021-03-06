#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "Status.h"

#include <string>
#include <vector>

void readFile(const std::string& file, const Status& status);
void createNewFile(const char* newFileName);
void appendStringToFile(const char* fileName, const std::string& input);
void endingMessage(const Status& status);

bool fileExists(const char* fileName);
bool isValidFileName(const std::string& fileName);

void readForGather(const std::string& file, std::vector<std::string>& lineVector);

#endif
