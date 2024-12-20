#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long dp[100'001];

int main() {
    FastIO
    int n, zSum = 0;
    cin >> n;
    fill(dp + 1, dp + 100'000 + 1, 1e18);
    for (int i = 0; i < n; i++) {
        int x, y, z, cost;
        cin >> x >> y >> z;
        zSum += z;
        if (x > y) {
            cost = 0;
        } else {
            cost = y - (x + y) / 2;
        }
        for (int j = 100'000; j >= z; j--) {
            dp[j] = min(dp[j], cost + dp[j - z]);
        }
    }
    long long ans = 1e18;
    for (int z = (zSum + 1) / 2; z <= zSum; z++) {
        ans = min(ans, dp[z]);
    }
    cout << ans;
    return 0;
}