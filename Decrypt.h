#ifndef DECRYPT_H
#define DECRYPT_H

#include "Status.h"

#include <string>

void beginDecryption(std::string& line, int& encryptionKey, Status status, const char* FileWritingTo);		//Status address& ???
void decryptWithoutKey();
int decryptChar(int encryptionKey, int fileCharNum, bool isUpper);

#endif
