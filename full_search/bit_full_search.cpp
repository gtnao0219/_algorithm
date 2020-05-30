#include<bits/stdc++.h>
using namespace std;

int main() {
    // sample number of digits
    int n = 5;

    for (int bit = 0; bit < (1 << n); ++bit) {
        // each digit
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                // debug
                cout << i << " ";
            }
        }
        // debug
        cout << endl;
    }
}
