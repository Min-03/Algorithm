#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[10'001];

int main() {
    FastIO
    int n, k;
    dp[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = num; j <= k; j++) {
            dp[j] += dp[j - num];
        }
    }
    cout << dp[k];
    return 0;
}