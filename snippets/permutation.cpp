#include<bits/stdc++.h>
using namespace std;

void permutation() {
    // plz set a appropriate vector
    vector<int> vec = {3, 2, 1, 0};
    sort(vec.begin(), vec.end());
    do {
        // implement me
    } while (next_permutation(vec.begin(), vec.end()));
}

int main() {
    vector<int> vec = {3, 2, 1, 0};
    sort(vec.begin(), vec.end());
    do {
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(vec.begin(), vec.end()));
}
