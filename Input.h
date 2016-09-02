#ifndef INPUT_H
#define INPUT_H

#include "Status.h"

#include <string>

#define CIPHER_SIZE 26

void initialization(std::string& command, std::string& file, Status& status);

void getUserInput(std::string& command, std::string& file);
void interpretInput(std::string userInput, std::string& command, std::string& file);
void splitCommand(std::string userInput, std::string& command, unsigned int& fileStartingPoint);
void splitFile(std::string userInput, std::string& file, unsigned int startingPoint);

void userInputCheck(std::string& command, std::string& file, Status& status);
void checkCommand(std::string& command, std::string& file, Status& status);
void checkFile(std::string& command, std::string& file, Status& status);
void exitCheck(std::string command);
bool isClearCommand(std::string command);

void getEncryptionKey(int& encryptionKey, Status& status);

void splitFileAlternate(std::string userInput, std::string& file, unsigned int startingPoint);
void checkFileAlternate(std::string& command, std::string& file, Status& status);

#endif
