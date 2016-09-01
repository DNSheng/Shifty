#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <string>

void ReadFile(const char* fileName, int encryptionKey, bool decrypting, bool encrypting);
void WriteFile(const char* fileName);

#endif
