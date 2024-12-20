#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const double eps = 1e-9;

struct Point {
    double x = 0, y = 0, z = 0;
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
    while (dist(lo, a) + eps < dist(hi, a)) {
        Point mid = {(lo.x + hi.x) / 2, (lo.y + hi.y) / 2, (lo.z + hi.z) / 2};
        if (dist(lo, c) + eps < dist(hi, c)) hi = mid;
        else lo = mid;
    }
    cout << fixed;
    cout << setprecision(10);
    cout << dist(lo, c);
    return 0;
}