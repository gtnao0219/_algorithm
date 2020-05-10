#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct ConvexHullTrick {
    typedef pair< T, T > Line;
    vector<Line> lines;
    ConvexHullTrick() {}
    bool is_unnecessary(Line check_line, Line line_1, Line line_2) {
        if (line_1 < line_2) swap(line_1, line_2);
        return (line_2.second - check_line.second) * (check_line.first - line_1.first) >= (check_line.second - line_1.second) * (line_2.first - check_line.first);
    }
    void add(T a, T b) {
        Line line = make_pair(a, b);
        while (lines.size() >= 2 && is_unnecessary(lines.back(), *(lines.end() - 2), line)) {
            lines.pop_back();
        }
        int ng = -1;
        int ok = lines.size();
        int idx = binary_search(ng, ok, [&](long long idx) {
            return lines[idx].first >= line.first;
        });
        lines.insert(lines.begin() + idx, line);
    }
    T f(T idx, T x) {
        Line line = lines[idx];
        return line.first * x + line.second;
    }
    int query(T x) {
        int ng = -1;
        int ok = lines.size() - 1;
        int idx = binary_search(ng, ok, [&](long long idx) {
            return f(idx, x) < f(idx + 1, x);
        });
        return f(idx, x);
    }

    template <typename TFunc>
    long long binary_search(long long ng, long long ok, TFunc is_ok) {
        while (abs(ok - ng) > 1) {
            long long mid = (ok + ng) / 2;
            if (is_ok(mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }
};

int main() {
    ConvexHullTrick<int> cht;
    cht.add(2, 0);
	std::cout << "Add y=2x" << std::endl;
	std::cout << "min(f(-2)) = " << cht.query(-2) << std::endl;
	std::cout << "min(f(2)) = " << cht.query(2) << std::endl << std::endl;

	cht.add(0, -1);
	std::cout << "Add y=-1" << std::endl;
	std::cout << "min(f(-2)) = " << cht.query(-2) << std::endl;
	std::cout << "min(f(2)) = " << cht.query(2) << std::endl << std::endl;

	cht.add(1, 1);
	std::cout << "Add y=x+1" << std::endl;
	std::cout << "min(f(-2)) = " << cht.query(-2) << std::endl;
	std::cout << "min(f(2)) = " << cht.query(2) << std::endl << std::endl;

	cht.add(-1, 0);
	std::cout << "Add y=-x" << std::endl;
	std::cout << "min(f(-2)) = " << cht.query(-2) << std::endl;
	std::cout << "min(f(2)) = " << cht.query(2) << std::endl << std::endl;
}