# Description
Shifty is a simple program that can encrypt and decrypt a message using the simple shift (Caesar) cipher. This cipher is only applied to english alphabetical characters (omits numbers and symbols) and is not case-sensitive. Therefore, it uses a key in the range of 
1 to 26 (as 0 implies no change). Any encryption or decryption is done by reading a .txt file in the same directory as the program. 
Currently, the program is unable to write the ciphertext or plaintext to a new file, but it may change in a future update. For now, 
ciphertext and plaintext is outputted in the window.

#Encryption
Encryption is done by entering the **encrypt** command followed by the **file name**.
```
> encrypt file.txt
```
After which, the user is prompted to enter the encryption key. Any valid integer will work, although anything more than 26 will return the modulus from 26. A negative integer will still return the modulus from 26, but as expected will work backwards. For example, a key of -1 is equivalent to 25.

After encryption is complete, a new file containing the ciphertext is created in the same directory as ***file.txt***, named ***file_encrypted.txt***. If however, a file with the name ***file_encrypted.txt*** exists, it will be overwritten without warning. This is to be fixed in a later patch.

#Decryption
Decryption is done by entering the **decrypt** command followed by the **file name**.
```
> decrypt file.txt
```
After which, the user is prompted to enter the decryption key. Any valid integer will work, although anything more than 26 will return the modulus from 26. Entering 0 will start a brute force operation which is yet to be implemented. A negative integer will still return the modulus from 26, but as expected will work backwards. For example, a key of -1 is equivalent to 25.

After decryption is complete, a new file containing the plaintext is created in the same directory as ***file.txt***, named ***file_decrypted.txt***.If however, a file with the name ***file_decrypted.txt*** exists, it will be overwritten without warning. This is to be fixed in a later patch.

#Upcoming
Shifty is not entirely complete, as there are a few key features I would like to implement eventually.
+ Brute force decryption
  + Five most common alphabetical characters are assumed to be 'e'.
  + Returns the decryption key as if the character was 'e' and uses it to decrypt the rest of the text.
  + Gives user a sample of the five options with the decryption key used.
    + If it is one of the options, user enters which one and the rest is decrypted.
    + If it is not one of the options, brute force with the remaining keys and display a sample with the decryption key used.
+ Writing ciphertext/plaintext output to a new file with a custom name/location.
  + Creating a user prompt/check if that file already exists
+ Modifying the "cls" command to not use system() to make it safer, but to also allow for different OS compatibility.
+ Description upon opening the program.
  + Name of program
  + Command for help menu
    + Create a help menu
  + Name of author
+ Include screenshots of the program
