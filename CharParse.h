#ifndef CHARPARSE_H
#define CHARPARSE_H

#include "Status.h"

#include <string>

#define LOWERCASE_A_BOUND 97
#define LOWERCASE_Z_BOUND 122
#define UPPERCASE_A_BOUND 65
#define UPPERCASE_Z_BOUND 90

static std::string parseCharFinalResult;

void parseChar(int encryptionKey, char fileChar, Status status, const char* fileWritingTo);		//Status address& ?
void passingCharInLine(std::string& line, int& encryptionKey, Status status, const char* fileWritingTo);	//Status address& ?

#endif
