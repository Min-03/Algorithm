#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> taste;
int used[10];
int n, ans = 2e9;

void go(int curr, int chooseNum) {
    if (curr == n) {
        if (chooseNum == 0) return;
        int sour = 1, bit = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) continue;
            auto [a, b] = taste[i];
            sour *= a;
            bit += b;
        }
        ans = min(ans, abs(sour - bit));
        return;
    }
    used[curr] = true;
    go(curr + 1, chooseNum + 1);
    used[curr] = false;
    go(curr + 1, chooseNum);
}

int main() {
    FastIO
    cin >> n;
    taste.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        taste[i] = {a, b};
    }
    go(0, 0);
    cout << ans;
    return 0;
}