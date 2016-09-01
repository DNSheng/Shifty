#ifndef CHARPARSE_H
#define CHARPARSE_H

#include <string>

#define LOWERCASE_A_BOUND 97
#define LOWERCASE_Z_BOUND 122
#define UPPERCASE_A_BOUND 65
#define UPPERCASE_Z_BOUND 90

void parseChar(int encryptionKey, char fileChar, bool& decrypting, bool& encrypting);
void passingCharInLine(std::string& line, int& encryptionKey, bool& decrypting, bool& encrypting);

#endif
