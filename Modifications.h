#ifndef MODIFICATIONS_H
#define MODIFICATIONS_H

#include "Status.h"

#include <string>

#define LOWERCASE_A_BOUND 97
#define LOWERCASE_Z_BOUND 122
#define UPPERCASE_A_BOUND 65
#define UPPERCASE_Z_BOUND 90

static std::string modifiedLine;

void modifyChar(int encryptionKey, char fileChar, Status status, const char* fileWritingTo);
void modifyLine(std::string& line, int encryptionKey, Status status, const char* fileWritingTo);


#endif
