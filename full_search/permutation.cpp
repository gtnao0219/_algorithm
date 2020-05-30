#include<bits/stdc++.h>
using namespace std;

int main() {
    // prepare sample data
    vector<int> vec = {3, 2, 1, 0};
    // sort is required
    sort(vec.begin(), vec.end());

    do {
        for (int i : vec) {
            // debug
            cout << i << " ";
        }
        // debug
        cout << endl;
    } while (next_permutation(vec.begin(), vec.end()));
}
