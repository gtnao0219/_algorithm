#include<bits/stdc++.h>
using namespace std;

// x, y. x and y is 0-indexed.
using Point = pair<int, int>;
// [l, r), l and r is 0-indexed.
template<typename T>
using Interval2d = tuple<Point, Point, T>;

template<typename T>
struct Imos2d {
    int h, w;
    vector<vector<T>> s;
    Imos2d(int h, int w, const vector<Interval2d<T>> &intervals) : h(h), w(w) {
        s.resize(h + 1, vector<T>(w + 1, 0));
        for (auto interval : intervals) {
            T v = std::get<2>(interval);
            Point p1 = std::get<0>(interval);
            Point p2 = std::get<1>(interval);
            s[p1.second][p1.first] += v;
            s[p1.second][p2.first] -= v;
            s[p2.second][p1.first] -= v;
            s[p2.second][p2.first] += v;
        }
        for (int y = 0; y < h; ++y) for (int x = 0; x < w; ++x) {
            s[y + 1][x] += s[y][x];
        }
        for (int y = 0; y < h; ++y) for (int x = 0; x < w; ++x) {
            s[y][x + 1] += s[y][x];
        }
    }
    int height() {
        return h;
    }
    int width() {
        return w;
    }
    // x, y. x and y is 0-indexed.
    T get(int x, int y) {
        return s[y][x];
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B
*/
int main() {
    int N; cin >> N;
    vector<Interval2d<long long>> intervals(N);
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        intervals[i] = make_tuple(make_pair(x1, y1), make_pair(x2, y2), 1);
    }
    Imos2d<long long> imos(1001, 1001, intervals);

    long long res = numeric_limits<long long>::min();
    for (int y = 0; y < imos.height(); ++y) for (int x = 0; x < imos.width(); ++x) {
        res = max(res, imos.get(x, y));
    }
    cout << res << endl;
}
