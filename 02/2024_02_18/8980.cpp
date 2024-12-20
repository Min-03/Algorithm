#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct box {
    int s, e, w;
    bool operator <(const box oth) const {
        return e < oth.e;
    }
};

vector<box> boxes;
int remain[2001];

int main() {
    FastIO
    int n, c, m;
    cin >> n >> c >> m;
    boxes.resize(m);
    for (int i = 0; i < m; i++) cin >> boxes[i].s >> boxes[i].e >> boxes[i].w;
    sort(boxes.begin(), boxes.end());
    for (int i = 1; i <= n; i++) remain[i] = c;

    int ans = 0;
    for (auto [s, e, w] : boxes) {
        int carry = w;
        for (int i = s; i < e; i++) carry = min(carry, remain[i]);
        ans += carry;
        for (int i = s; i < e; i++) remain[i] -= carry;
    }
    cout << ans;
    return 0;
}