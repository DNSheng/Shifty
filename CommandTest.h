#ifndef COMMAND_TEST_H
#define COMMAND_TEST_H

#include <string>
#include "Status.h"

#define CIPHER_SIZE 26

void initializationTEST(std::string& command, std::string& file, Status& status);
void getUserInputTEST(std::string& command, std::string& file);
void interpretInputTEST(std::string userInput, std::string& command, std::string& file);
void splitCommandTEST(std::string userInput, std::string& command, unsigned int& fileStartingPoint);
void splitFileTEST(std::string userInput, std::string& file, unsigned int startingPoint);
void userInputCheckTEST(std::string& command, std::string& file, Status& status);
void checkCommandTEST(std::string& command, std::string& file, Status& status);
void checkFileTEST(std::string& command, std::string& file, Status& status);
void exitCheckTEST(std::string command);
bool isClearCommandTEST(std::string command);
void getEncryptionKeyTEST(int& encryptionKey, Status& status);

#endif
