#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> points; // 지점, 변화량
priority_queue<int> pq;
priority_queue<int> del;

void delElm() {
    while (!del.empty() && pq.top() == del.top()) {
        pq.pop();
        del.pop();
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    points.resize(2 * n);
    for (int i = 0; i < n; i++) {
        int l, h, r;
        cin >> l >> h >> r;
        points[2 * i] = {l, h};
        points[2 * i + 1] = {r, - h};
    }

    sort(points.begin(), points.end());

    int prevPoint = 0, before = -1, ans = -1, befPositive = -1;
    for (auto [point, h] : points) {
        if (ans != -1) {
            if (point != prevPoint) {
                cout << prevPoint << ' ' << ans << ' ';
            }
            ans = -1;
        }
        if (h > 0) {
            pq.push(h);
        } else {
            del.push(-h);
        }
        delElm();

        int now = 0;
        if (!pq.empty()) {
            now = pq.top();
        }
        if (now != before && !(prevPoint == point && befPositive == h)) {
            ans = now;
        }
        if (now > 0 && !(point == prevPoint && h < 0)) befPositive = now;
        before = now;
        prevPoint = point;
    }

    if (ans != -1) {
        cout << prevPoint << ' ' << ans << ' ';
    }
    return 0;
}