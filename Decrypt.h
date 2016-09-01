#ifndef DECRYPT_H
#define DECRYPT_H

#include <string>

void beginDecryption(std::string& line, int& encryptionKey, bool& decrypting, bool& encrypting);
void decryptWithoutKey();
int decryptChar(int encryptionKey, int fileCharNum, bool isUpper);

#endif