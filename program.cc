/*
*   file name: program.cc
*   Name: Kyle Willis
*   Date: 3-5-19
*   Description: This program is designed to encrypt or decrypt a file that the
*   the user inputs
*
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//Fuction prototypes

//display menu
void displayMenu();

//Set the shift key
void shiftKey(int &newKey);

//File encryption
void encryptFile(int key);

//File decryption
void decryptFile(int key);

int main() {
    int choice, key;
    key = 3; //default
    do {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            // call the set key function and assign to key
            shiftKey(key);
        }
        else if (choice == 2) {
            //call the encryption function
            encryptFile(key);
        }
        else if (choice == 3) {
            //call the decryption function
            decryptFile(key);
        }
    } while(choice !=4);
    return 0;
}

//Functions 

//Display menu
void displayMenu(){
    cout << "1. Set the shift key value (default is 3)" << endl;
    cout << "2. Encrypt a file" << endl;
    cout << "3. Decrypt a file" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter a choice: ";
}

//Shift key
void shiftKey(int &newKey) {
    do {
        cout << "Enter a value between 1-10: ";
        cin >> newKey;
    } while(newKey > 10 || newKey < 1);
}

//Encryption function
void encryptFile(int key) {
    //Declare all variables
    ifstream inStream;
    ofstream outStream;
    string inputFile, outFile;
    char ch;
    //Get input file name
    cout << "Enter the input file name: ";
    cin >> inputFile;
    inStream.open(inputFile);
    
    //Check for input failure
    if(inStream.fail()){
        cout << "Failed to open up the input file";
        exit(1);
    }

    //Get output file name
    cout << "Enter the output file name: ";
    cin >> outFile;
    outStream.open(outFile);

    //Check for output failure
    if(outStream.fail()) {
        cout << "Failed to open up the output file";
        exit(1);
    }

    //Apply the key to the file
    inStream.get(ch);
    while(!inStream.eof()){
        ch = ch + key;
        outStream << ch;
        inStream.get(ch);
    }

    //Close files
    inStream.close();
    outStream.close();
}

//Decryption function
void decryptFile(int key) {
    //Declare all variables
    ifstream inStream;
    ofstream outStream;
    string inputFile, outFile;
    char ch;
    //Get input file name
    cout << "Enter the file name to decrypt: ";
    cin >> inputFile;
    inStream.open(inputFile);
    
    //Check for input failure
    if(inStream.fail()){
        cout << "Failed to open up the input file";
        exit(1);
    }

    //Get output file name
    cout << "Enter the output file name: ";
    cin >> outFile;
    outStream.open(outFile);

    //Check for output failure
    if(outStream.fail()) {
        cout << "Failed to open up the output file";
        exit(1);
    }

    //Apply the key to the file
    inStream.get(ch);
    while(!inStream.eof()){
        ch = ch - key;
        outStream << ch;
        inStream.get(ch);
    }

    //Close files
    inStream.close();
    outStream.close();
}