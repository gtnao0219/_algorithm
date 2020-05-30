#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct TwoDimensionsCumulativeSum {
    vector<vector<T>> s;
    TwoDimensionsCumulativeSum(const vector<vector<T>> &grid) {
        int h = grid.size();
        int w = grid[0].size();
        s.resize(h + 1, vector<T>(w + 1, 0));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + grid[i][j];
            }
        }
    }
    // [x1, x2) [y1, y2), x1 and x2, y1, y2 is 0-indexed.
    T sum(int x1, int x2, int y1, int y2) {
        return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
    }
};

// In
// 4 5
// 1 8 7 3 2
// 9 1 3 4 6
// 3 5 8 1 4
// 2 7 3 2 5
// 3
// 1 3 2 5
// 0 2 1 3
// 0 4 0 5
// 
// Out
// 26
// 19
// 84
int main() {
    int H, W; cin >> H >> W;
    vector<vector<int> > grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> grid[i][j];

    TwoDimensionsCumulativeSum<int> cs(grid);

    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << cs.sum(x1, x2, y1, y2) << endl;
    }
}
