#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

pair<int, int> points[20];
bool add[20];
int n;
double ans = -1;

void go(int curr, int chooseNum) {
    if (chooseNum > n / 2) return;
    if (curr == n) {
        if (chooseNum != n / 2) return;
        long long ansX = 0, ansY = 0;
        for (int i = 0; i < n; i++) {
            auto [x, y] = points[i];
            if (add[i]) {
                ansX += x;
                ansY += y;
            } else {
                ansX -= x;
                ansY -= y;
            }
        }
        double dist = sqrt(ansX * ansX + ansY * ansY);
        if (ans == -1 || dist < ans) ans = dist;
        return;
    }
    add[curr] = true;
    go(curr + 1, chooseNum + 1);
    add[curr] = false;
    go(curr + 1, chooseNum);
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        ans = -1;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
        go(0, 0);
        printf("%.10lf\n", ans);
    }
    return 0;
}