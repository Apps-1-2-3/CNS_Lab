#include <iostream>
using namespace std;

int main() {
    int bucketSize, outputRate;
    int n;
    int stored = 0;

    cout << "Enter bucket size: ";
    cin >> bucketSize;

    cout << "Enter output rate: ";
    cin >> outputRate;

    cout << "Enter number of incoming packets: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int packetSize;

        cout << "\n----------------------------------------\n";
        cout << "Enter packet " << i << " size: ";
        cin >> packetSize;

        cout << "Incoming packet size = " << packetSize << " bytes\n";

        if (packetSize + stored > bucketSize) {
            int discarded = (packetSize + stored) - bucketSize;
            stored = bucketSize;

            cout << "Bucket overflow!\n";
            cout << "Discarded data = " << discarded << " bytes\n";
        } else {
            stored += packetSize;
            cout << "Packet accepted.\n";
        }

        cout << "Data currently in bucket = " << stored << " bytes\n";

        int sent;

        if (stored >= outputRate) {
            sent = outputRate;
        } else {
            sent = stored;
        }

        stored -= sent;

        cout << "Data transmitted = " << sent << " bytes\n";
        cout << "Data left in bucket = " << stored << " bytes\n";
    }

    cout << "\n----------------------------------------\n";
    cout << "Sending remaining data from bucket...\n";

    while (stored > 0) {
        int sent;

        if (stored >= outputRate) {
            sent = outputRate;
        } else {
            sent = stored;
        }

        stored -= sent;

        cout << "Data transmitted = " << sent << " bytes";
        cout << " | Data left = " << stored << " bytes\n";
    }

    cout << "\nAll packets processed. Bucket is empty.\n";

    return 0;
}