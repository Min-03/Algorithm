#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[41];

int main() {
    FastIO
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n, m, curr = 0, res = 1;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int vip;
        cin >> vip;
        res *= dp[vip - curr - 1];
        curr = vip;
    }
    res *= dp[n - curr];
    cout << res;
    return 0;
}