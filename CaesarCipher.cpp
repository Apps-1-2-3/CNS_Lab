#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string caesarEncrypt(string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base;
            if (islower(ch))
                base = 'a';
            else
                base = 'A';

            text[i] = (ch - base + shift) % 26 + base;
        }
    }

    return text;
}

string caesarDecrypt(string text, int shift) {
    return caesarEncrypt(text, 26 - shift);
}

int main() {
    int choice;
    string text;

    while (true) {
        cout << "\n1. Caesar Encrypt";
        cout << "\n2. Caesar Decrypt";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;


        if (choice == 1) {
            cout << "Enter text: ";
            cin >> text;

            cout << "Encrypted: " << caesarEncrypt(text, 3) << endl;
        }

        else if (choice == 2) {
            cout << "Enter text: ";
            cin >> text;

            cout << "Decrypted: " << caesarDecrypt(text, 3) << endl;
        }

        else if (choice == 3) {
            break;
        }

        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}