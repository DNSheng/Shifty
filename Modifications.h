#ifndef MODIFICATIONS_H
#define MODIFICATIONS_H

#include "Status.h"

#include <vector>
#include <string>

#define LOWERCASE_A_BOUND 97
#define LOWERCASE_Z_BOUND 122
#define UPPERCASE_A_BOUND 65
#define UPPERCASE_Z_BOUND 90

static std::string modifiedLine;

char charEncryption(const int& encryptionKey, const char& fileChar);

void normalModifyChar(const int& encryptionKey, const char& fileChar, const char* fileWritingTo);
void modifyLine(std::string& line, const int& encryptionKey, const char* fileWritingTo);

void bruteModifyLine(const std::string& bestLine, std::vector<std::string>& decryptions);
void bruteModifyChar(const int& encryptionKey, const char& fileChar, std::string& currentLine);

#endif
