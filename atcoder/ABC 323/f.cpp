#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
    FastIO
    long long xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    vector<pair<long long, long long>> points;
    if (xb < xc) points.push_back({xb - 1, yb});
    if (xb > xc) points.push_back({xb + 1, yb});
    if (yb < yc) points.push_back({xb, yb -1});
    if (yb > yc) points.push_back({xb, yb + 1});

    if (xb == xc || yb == yc) {
        auto [x, y] = points[0];
        cout << abs(xb - xc) + abs(yb - yc) + abs(xa - x) + abs(ya - y);
    } else {
        auto [x1, y1] = points[0];
        auto [x2, y2] = points[1];
        long long dist = min(abs(xa - x1) + abs(ya - y1), abs(xa - x2) + abs(ya - y2));
        cout << dist + abs(xb - xc) + abs(yb - yc) + 2;
    }
    return 0;
}