
#include <iostream>
#include <string>
using namespace std;

string divide(string data, string gen) {
    int n = gen.length();

    for (int i = 0; i <= data.length() - n; i++) {
        if (data[i] == '1') {
            for (int j = 0; j < n; j++) {
                data[i + j] =
                    (data[i + j] == gen[j]) ? '0' : '1';
            }
        }
    }

    return data.substr(data.length() - n + 1);
}

int main() {
    string data, gen = "10001000000100001";

    cout << "Enter data: ";
    cin >> data;

    string padded = data + string(gen.length() - 1, '0');

    cout << "Generating polynomial: " << gen << endl;
    cout << "Modified data is: " << padded << endl;

    string rem = divide(padded, gen);

    cout << "Checksum is: " << rem << endl;

    string codeword = data + rem;

    cout << "Final code word is: " << codeword << endl;

    int choice;
    cout << "Test error detection 0(yes) 1(no)? : ";
    cin >> choice;

    if (choice == 0) {
        int pos;
        cout << "Enter the position where error is to be inserted: ";
        cin >> pos;

        codeword[pos - 1] =
            (codeword[pos - 1] == '0') ? '1' : '0';

        cout << "Erroneous data: " << codeword << endl;
    }

    string check = divide(codeword, gen);

    bool error = false;

    for (char c : check)
        if (c == '1')
            error = true;

    if (error)
        cout << "Error detected" << endl;
    else
        cout << "No error detected" << endl;

    return 0;
}