# Description
Shifty is a simple program that can encrypt and decrypt a message using the simple shift (Caesar) cipher. This cipher is only applied to 
english alphabetical characters (omits numbers and symbols) and is not case-sensitive. Therefore, it uses a key in the range of 
1 to 26 (as 0 implies no change). Any encryption or decryption is done by reading a .txt file in the same directory as the program. 
Currently, the program is unable to write the ciphertext or plaintext to a new file, but it may change in a future update. For now, 
ciphertext and plaintext is outputted in the window.

#Encryption
Encryption is done by entering the **encrypt** command followed by the **file name**.
```
> encrypt file.txt
```
After which, the user is prompted to enter the encryption key. Any valid positive integer will work, although anything more than 26 will
return the modulus from 26.

#Decryption
Decryption is done by entering the **decrypt** command followed by the **file name**.
```
> decrypt file.txt
```
After which, the user is prompted to enter the decryption key. Any valid positive integer will work, although anything more than 26 will
return the modulus from 26. Entering 0 will start a brute force operation which is yet to be implemented.

#Upcoming
Shifty is not entirely complete, as there are a few key features I would like to implement eventually.
+ Brute force decryption
  + Five most common alphabetical characters are assumed to be 'e'.
  + Returns the decryption key as if the character was 'e' and uses it to decrypt the rest of the text.
  + Gives user a sample of the five options with the decryption key used.
    + If it is one of the options, user enters which one and the rest is decrypted.
    + If it is not one of the options, brute force with the remaining keys and display a sample with the decryption key used.
+ Handle negative integer input for decryption/encryption key.
  + Simple as a method to check for negativity.
    + Assuming **X** is the integer, **26 + X** is the equivalent key.
+ Writing ciphertext/plaintext output to a new file if prompted.
  + Default name created, but user can change name if they so wish.
+ Description upon opening the program.
  + Name of program
  + Command for help menu
    + Create a help menu
  + Name of author
+ Splitting program into different source files and headers for more organized layout.
  + Main function calling other functions
  + Input handling
  + Help Menu
  + Simple encryption/decryption
  + File writing/reading
  + Brute force decryption
