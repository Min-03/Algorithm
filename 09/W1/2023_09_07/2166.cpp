#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

pair<long long, long long> points[10000];
int n;

//index가 a, b, c인 점으로 이루어진 삼각형의 넓이를 구함
double triangleSize(int a, int b, int c) {
    auto [x1, y1] = points[a];
    auto [x2, y2] = points[b];
    auto [x3, y3] = points[c];
    return (double) (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans += triangleSize(0, i, i + 1);
    }
    cout << fixed << setprecision(1) << abs(ans);
    return 0;
}