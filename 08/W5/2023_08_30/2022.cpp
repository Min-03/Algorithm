#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const double eps = 1e-6;

double x, y, c;

bool check(double a) {
    if (x < a || y < a) return true;
    double dist =  sqrt((x * x - a * a) * (y * y - a * a)) / (sqrt(x * x - a * a) + sqrt(y * y - a * a));
    return dist < c + eps;
}

int main() {
    FastIO
    cin >> x >> y >> c;
    double lo = 0, hi = max(x, y);
    while (abs(lo - hi) > eps) {
        double mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << lo;
    return 0;
}