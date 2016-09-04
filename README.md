# Description
Shifty is a simple program that can encrypt and decrypt a message using the simple shift (Caesar) cipher. This cipher is only applied to english alphabetical characters (omits numbers and symbols) and is not case-sensitive. Therefore, it uses a key in the range of 
1 to 26 (as 0 implies no change). Any encryption or decryption is done by reading a .txt file in the same directory as the program. 
The final encrypted or decrypted data is then written to a new file in the same directory.

#Installation
Currently, the program is made only for Windows operating systems as the code utilizes commands such as system("cls"). This may be updated in the future.

To install the program, simply download the source files and compile them yourself using an IDE or g++ compiler manually. The resulting .exe program can be placed anywhere, but best placed in the PATH for easy access through the command prompt.

#Input
Shifty takes input of the form:
```
> [COMMAND] [FILE_LOCATION]
```
Special commands not requiring a file can simply be entered on their own accord:
```
> [COMMAND]
```

#Commands
##Special Commands
Special commands include:
```
> help
```
The help command brings up a brief tutorial on how to run shifty.
```
> clear
```
The clear command clears the screen.
```
> exit
```
The exit command exits the program.

##Encryption
Encryption is done by entering the **encrypt** command followed by the **file name**.
```
> encrypt file.txt
```
After which, the user is prompted to enter the encryption key. Any valid integer will work, although anything more than 26 will return the modulus from 26. A negative integer will still return the modulus from 26, but as expected will work backwards. For example, a key of -1 is equivalent to 25.

After encryption is complete, a new file containing the ciphertext is created in the same directory as ***file.txt***, named ***file_encrypted.txt***. If however, a file with the name ***file_encrypted.txt*** exists, it will be overwritten without warning. This is to be fixed in a later patch.

##Decryption
Decryption is done by entering the **decrypt** command followed by the **file name**.
```
> decrypt file.txt
```
After which, the user is prompted to enter the decryption key. Any valid integer will work, although anything more than 26 will return the modulus from 26. Entering 0 will start a brute force operation which is yet to be implemented. A negative integer will still return the modulus from 26, but as expected will work backwards. For example, a key of -1 is equivalent to 25.

After decryption is complete, a new file containing the plaintext is created in the same directory as ***file.txt***, named ***file_decrypted.txt***.If however, a file with the name ***file_decrypted.txt*** exists, it will be overwritten without warning. This is to be fixed in a later patch.

##File location
Without specifying the folder, shifty assumes that the file is located in the same directory as the program.
However, accessing a text file in a different folder must include the entire path.

Windows Example:
```
> encrypt C:\Users\Dan\Desktop\file.txt
```

#Patch Notes
##Sept. 4, 2016 v0.82
+ Removed Encrypt.cpp and Decrypt.cpp, and merged them together forming Crypt.cpp
  + Encrypt.cpp and Decrypt.cpp now useless!
  + Crypt.cpp uses the same code as encryptChar() in Encrypt.cpp
  + Decryption works by modifying the encryptionKey to essentially CIPHER_SIZE - encryptionKey
    + simplifyKey() in Input.cpp modified for this to work
+ Reduced readFile() in FileHandling.cpp as a result of Crypt.cpp change
+ Created BruteForce.cpp in preparation of brute force solving, although it will come after fixes to getEncryptionKey() and createNewFile()
+ Removed code smell from getEncryptionKey(), reducing size of code as both options only differed by initial message.
  + Created a new method that outputs different message based on status
+ Modified all parameters of functions that were passed values
  + Changed anything passed by value to pass by const reference
  + This prevents copies from forming as:
  	+ They were not necessary
  	+ It reduces performance (although barely)

##Sept. 3, 2016 v0.81
+ Fixed bug where upon entering second valid command, program displayed:
```
> Error: No file given
```
  This was because newline was fed to userInput which created an empty command string. However, the program doesn't check for restart
  until after the file string was checked, so it ended up as a file error.
  
  The fix was done by calling checkRestart() after checkCommand().
+ Fixed bug where upon finishing encryption/decryption, program displayed:
```
> >
```
instead of:
```
> 
```
  This was because the newline character from getting the encryptionKey was passed to userInput in the next call of initialization().
  
  The fix was done by calling cin.ignore() after getting the encryptionKey.
  
##Sept. 2, 2016 v0.80
+ Complete rebuild done for input handling, file reading, file writing, and character encryption
  + Input handling now works by getting a single line and splitting it into a command and file location
    + More exceptions handled with additional accompanying error messages
    + Allowed for entering empty input (newline char) to continue prompting until a satisfactory input is entered
    + Input for encryptionKey is now checked, only allowing integers
      + Ex. -4, -27, -26, -100, -0, 0, 4, 25, 26, 27 will all work
      + Ex. a, -a, a-, 4a, -4a, 4a4 will not work
  + File reading now reads newline character
  + Fixed bug where non-alphabet characters were being ignored
  + File writing properly formats output to be identical to the input
+ Included a help menu
+ Included a start up menu

#Upcoming
Shifty is not entirely complete, as there are a few key features I would like to implement eventually.
+ Brute force decryption
  + Idea 1 (easier):
    + Five most common alphabetical characters are assumed to be 'e'.
    + Returns the decryption key as if the character was 'e' and uses it to decrypt the rest of the text.
    + Gives user a sample of the five options with the decryption key used.
      + If it is one of the options, user enters which one and the rest is decrypted.
      + If it is not one of the options, brute force with the remaining keys and display a sample with the decryption key used.
  + Idea 2 (harder):
    + Include a .txt file of english words
    + Take samples from the cipher text and apply all 26 decryptions
    + Compare from each decryption every word
      + Whichever has the most matching is most likely the right key
    + Use the key to decrypt the rest and output to file
+ Input for getEncryptionKey() still not secure at filtering invalid input
  + Things like: 0+, 0 +, 0 + /, etc. still work
  + Invalid input like examples above also cause shifty to run again, probably since it causes cin to carry the chars beyond the number to
    the next run of the program.
    + Ex. Something like "+ /" is still sitting in cin, and therefore get fed into userInput.
+ Writing ciphertext/plaintext output to a new file with a custom name/location.
  + Creating a user prompt/check if that file already exists
+ Modifying the "cls" command to not use system() to make it safer, but to also allow for different OS compatibility.
+ Include screenshots of the program in README
