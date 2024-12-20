#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dp[10'001];

int main() {
    FastIO
    int n, k;
    memset(dp, inf, sizeof(dp));
    dp[0] = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = num; j <= k; j++) dp[j] = min(dp[j], dp[j - num] + 1);
    }
    cout << (dp[k] == inf ? -1 : dp[k]);
    return 0;
}