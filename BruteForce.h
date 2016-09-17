#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <string>
#include <vector>

void startBruteForce(const std::string& file);
std::string getBestString(const std::string& file, std::vector<std::string>& lineVector);
void gatherLine(const std::string& sampleLine, std::vector<std::string>& lineVector);
std::string filterStrings(const std::vector<std::string>& lineVector);

void readVector(const std::vector<std::string>& vector);


void bruteForce(std::vector<std::string>& sample);			//Applies the transformation to all items in vector
															//Transformation overwrites the sample
															//Will be used for both 'samples' and 'initial'

void decryptSpecific(std::vector<std::string>& initial, int entryNum);
															//Decrypt a specific entry for display

void compareWords(std::vector<std::string>& sample);		//Compares the samples to a dictionary, and appends the
															//amount of matches at the end (at sample[26])

void displayEstimate(std::vector<std::string> initial);		//Displays the one with the best estimate
															//Afterwards, ask user to verify

void displayAll(std::vector<std::string> initial);			//Display all initial samples if estimate is wrong

#endif
