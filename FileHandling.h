#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>

void readFile(std::string fileName, int encryptionKey, bool decrypting, bool encrypting);
void createNewFile(const char* fileName);
void appendToFile(const char* fileName, std::string input);

#endif
