#include <iostream>
using namespace std;

// Function to calculate (base^power) % mod
int powerMod(int base, int power, int mod) {
    int result = 1;

    for (int i = 1; i <= power; i++) {
        result = (result * base) % mod;
    }

    return result;
}

int main() {
    int p, g;
    int a, b;
    int A, B;
    int keyAlice, keyBob;

    cout << "Enter prime number p: ";
    cin >> p;

    cout << "Enter primitive root g: ";
    cin >> g;

    cout << "Alice, enter private key a: ";
    cin >> a;

    A = powerMod(g, a, p);

    cout << "Alice sends A = " << A << " to Bob" << endl;

    cout << "\nBob, enter private key b: ";
    cin >> b;

    B = powerMod(g, b, p);

    cout << "Bob sends B = " << B << " to Alice" << endl;

    keyAlice = powerMod(B, a, p);
    keyBob = powerMod(A, b, p);

    cout << "\nShared key calculated by Alice = " << keyAlice << endl;
    cout << "Shared key calculated by Bob = " << keyBob << endl;

    if (keyAlice == keyBob) {
        cout << "Success! Shared secret key = " << keyAlice << endl;
    } else {
        cout << "Error! Keys do not match." << endl;
    }

    return 0;
}