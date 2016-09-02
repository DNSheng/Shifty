#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include "Status.h"

#define CIPHER_SIZE 26

void initialization(std::string& command, std::string& file, Status& status);
void getCommand(std::string& command, std::string& file, Status& status);
void commandCheck(std::string& command, std::string& file, Status& status);
void exitCheck(std::string& command);
bool isClear(std::string& command);
void getEncryptionKey(int& encryptionKey, Status& status);


#endif
