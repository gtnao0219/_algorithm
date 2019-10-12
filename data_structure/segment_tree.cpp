#include<bits/stdc++.h>
using namespace std;

template<typename Monoid>
struct SegmentTree {
    using BinaryOperation = function<Monoid(Monoid, Monoid)>;
    const BinaryOperation binary_operation;
    const Monoid identity_element;
    int n;
    vector<Monoid> dat;
    SegmentTree(int _n, const BinaryOperation bo, const Monoid ie) : binary_operation(bo), identity_element(ie) {
        n = 1;
        while(n < _n) n *= 2;
        dat.assign(n * 2, identity_element);
    }
    // k is 0-indexed.
    void set(int k, const Monoid &a) {
        dat[k + n] = a;
    }
    void build() {
        for (int k = n - 1; k > 0; --k) {
            dat[k] = binary_operation(dat[2 * k], dat[2 * k + 1]);
        }
    }
    // k is 0-indexed.
    void update(int k, const Monoid &a) {
        k += n;
        dat[k] = a;
        while (k >>= 1) {
            dat[k] = binary_operation(dat[2 * k], dat[2 * k + 1]);
        }
    }
    // [a, b), a and b are 0-indexed
    Monoid query(int a, int b) {
        Monoid v_left = identity_element, v_right = identity_element;
        for (int left = a + n, right = b + n; left < right; left >>= 1, right >>= 1) {
            if (left & 1) v_left = binary_operation(v_left, dat[left++]);
            if (right & 1) v_right = binary_operation(dat[--right], v_right);
        }
        return binary_operation(v_left, v_right);
    }
    // k is 0-indexed.
    Monoid operator[](const int &k) const {
        return dat[k + n];
    }
};

/*
    verified https://atcoder.jp/contests/arc008/tasks/arc008_4
*/
int main() {
    long long N;
    int M;
    cin >> N >> M;
    vector<long long> p(M);
    vector<double> a(M), b(M);
    for (int i = 0; i < M; ++i) {
        cin >> p[i] >> a[i] >> b[i];
        --p[i];
    }
    SegmentTree<pair<double, double>> st(
        N,
        [](pair<double, double> a, pair<double, double> b) {
            return make_pair(a.first * b.first, a.second * b.first + b.second);
        },
        make_pair(1, 0)
    );
    double res_min = 1.0, res_max = 1.0;
    for (int i = 0; i < M; ++i) {
        st.update(p[i], make_pair(a[i], b[i]));
        pair<double,double> res = st.query(0, N);
        res_min = min(res_min, res.first + res.second);
        res_max = max(res_max, res.first + res.second);
    }
    cout << fixed << setprecision(10) << res_min << endl << res_max << endl;
}
