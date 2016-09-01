#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

#define CIPHER_SIZE 26

void initialization(std::string& command, std::string& file, bool& decrypting, bool& encrypting);
void getCommand(std::string& command, std::string& file, bool& decrypting, bool& encrypting);
void commandCheck(std::string& command, std::string& file, bool& decrypting, bool& encrypting);
void exitCheck(std::string& command);
bool isClear(std::string& command);
void getEncryptionKey(int& encryptionKey, bool& decrypting, bool& encrypting);


#endif
