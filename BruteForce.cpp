#include "BruteForce.h"
#include "Input.h"		//For CIPHER_SIZE and getting user input for confirmation
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
 
#include <iostream>
#include <vector>

//MOVE THESE INITIAL DECLARATIONS TO THE HEADER FILE, PARAMETERS NOT FINISHED!

void getSamples(std::vector<std::string>& samples);		//Get samples from throughout the file based on file length
								//Fills vector with these
								//Parameters are file inputs and vector

void getInitialSamples(std::vector<std::string>& initial);	//Get initial sample based on file length
								//Fills vector with these
								//Parameters are file inputs and vector

void bruteForce(std::vector<std::string>& sample);		//Applies the transformation to all items in vector
								//Transformation overwrites the sample
								//Will be used for both 'samples' and 'initial'

void decryptSpecific(std::vector<std::string>& initial, int entryNum)
								//Decrypt a specific entry for display

void compareWords(std::vector<std::string>& sample);		//Compares the samples to a dictionary, and appends the
								//amount of matches at the end (at sample[26])

void displayEstimate(std::vector<std::string> initial);		//Displays the one with the best estimate
								//Afterwards, ask user to verify

void displayAll(std::vector<std::string> initial);		//Display all initial samples if estimate is wrong

void startBruteForce(const std::string& file)
{
	std::cout << "Not done yet..." << std::endl;
	
	std::vector<std::string> samples(CIPHER_SIZE);
	std::vector<std::string> initial(CIPHER_SIZE);
	std::vector<int> matches(CIPHER_SIZE);
	
	getSamples(samples);
	getInitialSamples(initial);
	
	exit(0);
}
