#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct Point {
    int x, y;
};

double getDist(Point p, Point q) {
    auto [x1, y1] = p;
    auto [x2, y2] = q;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    FastIO
    Point p, q, r;
    cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y;
    if ((p.x - q.x) * (q.y - r.y) == (p.y - q.y) * (q.x - r.x)) {
        cout << -1;
        return 0;
    }
    vector<double> lengths;
    lengths.push_back(2 * (getDist(p, q) + getDist(q, r)));
    lengths.push_back(2 * (getDist(p, r) + getDist(r, q)));
    lengths.push_back(2 * (getDist(q, p) + getDist(p, r)));
    auto [lo, hi] = minmax_element(lengths.begin(), lengths.end());
    cout << fixed << setprecision(14) << *hi - *lo;
    return 0;
}