#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool dp[51][1001];

int main() {
    FastIO
    int n, s, m;
    cin >> n >> s >> m;
    dp[0][s] = true;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        for (int j = 0; j <= m; j++) {
            if (!dp[i][j]) continue;
            if (j + v <= m) dp[i + 1][j + v] = true;
            if (j - v >= 0) dp[i + 1][j - v] = true;
        }
    }
    for (int j = m; j >= 0; j--) {
        if (dp[n][j]) {
            cout << j;
            return 0;
        }
    }
    cout << -1;
    return 0;
}