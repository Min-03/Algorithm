#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const double eps = 1e-9;

struct Point {
    double x = -1, y = -1, z = -1;
};

double dist(Point a, Point b) {
    double xDiff = a.x - b.x;
    double yDiff = a.y - b.y;
    double zDiff = a.z - b.z;
    return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
}

int main() {
    FastIO
    Point a, b, c;
    cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> c.x >> c.y >> c.z;
    Point lo = a, hi = b;
    while (dist(lo, hi) > eps) {
        Point p = {(2 * lo.x + hi.x) / 3, (2 * lo.y + hi.y) / 3, (2 * lo.z + hi.z) / 3};
        Point q = {(lo.x + 2 * hi.x) / 3, (lo.y + 2 * hi.y) / 3, (lo.z + 2 * hi.z) / 3};
        if (dist(p, c) < dist(q, c)) hi = q;
        else lo = p;
    }
    cout << fixed << setprecision(10) << dist(lo, c);
    return 0;
}