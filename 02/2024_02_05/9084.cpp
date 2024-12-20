#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[10001];

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int n, m;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            for (int i = num; i <= 10'000; i++) dp[i] += dp[i - num];
        }
        cin >> m;
        cout << dp[m] << '\n';
    }
    return 0;
}