#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encrypt(string text, string key) {
    string result = "";
    int j = 0;

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char plainChar = toupper(text[i]);
            char keyChar = toupper(key[j % key.length()]);

            char encryptedChar = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';

            result += encryptedChar;
            j++;
        } else {
            result += text[i];
        }
    }

    return result;
}

string decrypt(string text, string key) {
    string result = "";
    int j = 0;

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char cipherChar = toupper(text[i]);
            char keyChar = toupper(key[j % key.length()]);

            char decryptedChar = ((cipherChar - 'A') - (keyChar - 'A') + 26) % 26 + 'A';

            result += decryptedChar;
            j++;
        } else {
            result += text[i];
        }
    }

    return result;
}

int main() {
    int choice;
    string text, key;

    while (true) {
        cout << "\nVigenere Cipher";
        cout << "\n1. Encrypt";
        cout << "\n2. Decrypt";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 3) {
            break;
        }

        cout << "Enter text: ";
        getline(cin, text);

        cout << "Enter key: ";
        getline(cin, key);

        if (choice == 1) {
            cout << "Encrypted: " << encrypt(text, key) << endl;
        } 
        else if (choice == 2) {
            cout << "Decrypted: " << decrypt(text, key) << endl;
        } 
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}