#include<bits/stdc++.h>
using namespace std;

void bit_full_search() {
    // plz set a appropriate number
    int n = 5;
    for (int bit = 0; bit < (1 << n); ++bit) {
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                // implement me
                // ith bit flg is on
            }
        }
    }
}

int main() {
    int n = 5;
    for (int bit = 0; bit < (1 << n); ++bit) {
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
