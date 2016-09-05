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

void splitting(const std::string& userInput, std::string& command, std::string& file);
void splitCommand(const std::string& userInput, std::string& command, unsigned int& pointer);
void splitFile(const std::string& userInput, std::string& file, const unsigned int& pointer);

void checking(const std::string& command, std::string& file, Status& status);
void checkCommand(const std::string& command, Status& status);
void checkFile(const std::string& file, Status& status);
bool isValidFileExt(const std::string& file);
void checkRestart(std::string& file, Status& status);

void getEncryptionKey(int& encryptionKey, const Status& status);
void getKeyMessage(const Status& status);
bool isValidKey(const int& encryptionKey);
bool isNumber(const char& inputChar);
void simplifyKey(int& encryptionKey, const Status& status);

bool isOverwrite();
void getOverwriteInput(char& input);
std::string getNewFileName();

#endif
