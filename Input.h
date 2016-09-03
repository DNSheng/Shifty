#ifndef INPUT_H
#define INPUT_H

#include "Status.h"

#include <string>

#define CIPHER_SIZE 26
#define ASCII_ZERO	48
#define ASCII_NINE	57
#define ASCII_MINUS 45

static std::string command, userInput;

void initialization(std::string& file, Status& status);
void inputArrow();

void handleEmptyInput(std::string userInput, std::string& file, Status& status);

void splitting(std::string userInput, std::string& command, std::string& file);
void splitCommand(std::string userInput, std::string& command, unsigned int& pointer);
void splitFile(std::string userInput, std::string& file, unsigned int pointer);

void checking(std::string command, std::string& file, Status& status);
void checkCommand(std::string command, Status& status);
void checkFile(std::string file, Status& status);
void checkRestart(std::string& file, Status& status);

void getEncryptionKey(int& encryptionKey, Status status);
void simplifyKey(int& encryptionKey, Status status);
bool isValidKey(int encryptionKey);
bool isNumber(char inputChar);

#endif
