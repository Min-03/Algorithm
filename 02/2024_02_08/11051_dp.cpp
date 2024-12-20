#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int mod = 1e4 + 7;

int dp[1001][1001];

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    cout << dp[n][k];
    return 0;
}