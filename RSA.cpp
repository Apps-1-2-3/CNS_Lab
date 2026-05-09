#include <iostream>
using namespace std;

// Function to find GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular inverse
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1;
}

// Function to calculate (base^power) % mod
int powerMod(int base, int power, int mod) {
    int result = 1;

    for (int i = 1; i <= power; i++) {
        result = (result * base) % mod;
    }

    return result;
}

int main() {
    int p, q;
    int n, phi;
    int e, d;
    int message, cipher, decrypted;

    cout << "Enter two prime numbers p and q: ";
    cin >> p >> q;

    n = p * q;
    phi = (p - 1) * (q - 1);

    cout << "n = " << n << endl;
    cout << "phi = " << phi << endl;

    cout << "Enter e such that gcd(e, phi) = 1: ";
    cin >> e;

    if (gcd(e, phi) != 1) {
        cout << "Invalid e. gcd(e, phi) is not 1." << endl;
        return 0;
    }

    d = modInverse(e, phi);

    if (d == -1) {
        cout << "Private key not found." << endl;
        return 0;
    }

    cout << "Public Key  = (" << e << ", " << n << ")" << endl;
    cout << "Private Key = (" << d << ", " << n << ")" << endl;

    cout << "Enter message less than " << n << ": ";
    cin >> message;

    cipher = powerMod(message, e, n);
    cout << "Encrypted message = " << cipher << endl;

    decrypted = powerMod(cipher, d, n);
    cout << "Decrypted message = " << decrypted << endl;

    return 0;
}