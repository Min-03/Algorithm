#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long dp[21], newDp[21];

int main() {
    FastIO
    int n, first, target;
    cin >> n >> first;
    dp[first] = 1;
    for (int i = 0; i < n - 2; i++) {
        memset(newDp, 0, sizeof(newDp));
        int num;
        cin >> num;
        for (int j = num; j <= 20; j++) {
            newDp[j - num] += dp[j];
        }
        for (int j = 20 - num; j >= 0; j--) {
            newDp[j + num] += dp[j];
        }
        for (int j = 0; j <= 20; j++) dp[j] = newDp[j];
    }
    cin >> target;
    cout << dp[target];
    return 0;
}