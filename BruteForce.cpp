#include "BruteForce.h"
#include "Input.h"			//For getting user input for confirmation
#include "FileHandling.h"	//For writing final output to file, maybe for including dictionary.txt asset
#include "Modifications.h"	//For actually decrypting (may need to modify Modifications.cpp or here to take vectors)

/*
 * Obtain samples of text from the input. Get the first, last, middle, and halves.
 *   - The amount of halves will be based on the length of the input (more input, more halves).
 *   - Should be well distributed to allow for accuracy.
 *   - Avoid input of symbols and numbers, as they don't change in encryption or decryption.
 * Use a vector of size CIPHER_SIZE to hold samples.
 * For it's assigned entry in CIPHER_SIZE, use it as the encryptionKey
 *   - Use CIPHER_SIZE + 1 as containers are zero-indexed
 * Decrypt all samples in the vector and for each vector entry, compare with a dictionary of common words.
 * The most matches for common words is most likely correct
 * HOWEVER, error is common, therefore output a discretionary message with the decrypted samples with key
 *   - The output sample should always be the first few words so that the user can easily identify and verify
 *   - Ask if it is correct, and if not output all samples with accompanying key and let user choose.
 * Once the correct sample is chosen, ONLY THEN can the plaintext be written to a file.
 *   - This will require changes in both FileHandling.cpp and Modifications.cpp, with input handling in Input.cpp
 * Do I need to clear the vector after I'm finished, or does it go out of scope and get deleted?
 * How do I add/include a dictionary to the program, so that it is compiled within?
 *   - Just tell the user to include it in the same directory?
 *   - Make an awful array holding all the words?
 *   - http://www.dreamincode.net/forums/topic/150469-how-to-import-english-dictionary-in-c/
 */
 
 /*
  *	Try "/src/assets/dictionary.txt"
  *	Try "../src/assets/dictionary.txt"
  *	Or, try "../assests/dictionary.txt"	(This assumes a final build)
  */
#include <iostream>
#include <vector>

void startBruteForce(const std::string& file)
{
	std::vector<std::string> lineVector, decryptions;
	std::vector<int> matches;
	
	std::string bestLine = getBestString(file, lineVector);
	std::cout << "The best is: " << bestLine << std::endl;

	//Pass bestLine to be decrypted with 26 different keys, results put in decryptions vector
	bruteModifyLine(bestLine, decryptions);
	readVector(decryptions);
}

/*
 * Input:   The file path in the form of a string, and the vector that will
 * 		    hold all lines from the file
 * Output:  The string which has been determined to be the best to brute
 * 			force decrypt.
 * Desc.:	This returns the 'best' line. This is done by first reading
 * 			the file and collecting all strings in to each entry of the
 * 			vector. Then, each entry is tested with a function to determine
 * 			how 'good' it is based on certain attributes.
 */
std::string getBestString(const std::string& file, std::vector<std::string>& lineVector)
{
	readForGather(file, lineVector);
	std::cout << "Starting filterStrings()..." << std::endl;
	return filterStrings(lineVector);
}

/*
 * Input:	The current line in the file, the vector holding all lines in
 * 			the file.
 * Output:	None
 * Desc.:	This just takes the current line read from the file and pushes
 * 			it into the vector that will hold all the lines
 */
void gatherLine(const std::string& sampleLine, std::vector<std::string>& lineVector)
{
	lineVector.push_back(sampleLine);
}

/*
 * Input:	The vector containing all lines from the file
 * Output:	The string with the highest 'value' (aka the 'best' string)
 * Desc.:	This iterates through all the strings in the vector and for
 * 			each string, assigns it a value based on the amount of
 * 			alphabetical characters contained within. The one with the
 * 			highest value is the 'best' string.
 * 			For some reason, if the integers are not initialized then
 * 			the program doesn't function correctly.
 */
std::string filterStrings(const std::vector<std::string>& lineVector)
{
	int currentValue = 0, highestValue = 0, position = 0;

	std::vector<int> value;

	for(unsigned int i = 0; i < lineVector.size()-1; i++)
	{
		std::string currentLine = lineVector[i];

		for(unsigned int chars = 0; chars < currentLine.size(); chars++)
		{
			if(std::isalpha(currentLine[chars]))
			{
				currentValue++;
			}
		}
		value.push_back(currentValue);
		currentValue = 0;
	}

	for(unsigned int i = 0; i < value.size(); i++)
	{
		if(value[i] > highestValue)
		{
			position = i;
			highestValue = value[i];
		}
	}

	return lineVector[position];
}

void readVector(const std::vector<std::string>& vector)
{
	std::cout << "LISTING ALL ELEMENTS IN VECTOR:\n-----------" << std::endl;

	for(unsigned int i = 0; i < vector.size()-1; i++)
	{
		std::cout << i << ": " << vector[i] << std::endl;
	}
}
