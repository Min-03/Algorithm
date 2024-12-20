#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const long long mod = (long long) 1e9 + 7;

long long dp[2'000'001], m[2'000'001];

long long power(long long a, int b) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main() {
    FastIO
    int p, c, k;
    cin >> p >> c >> k;
    for (int i = 0; i < p; i++) {
        cin >> m[i];
    }
    dp[0] = m[0];

    for (int i = 1; i < p; i++) {
        dp[i] = (m[i] - m[i - 1]) % mod;
    }

    for (int i = p; i <= k; i++) {
        long long res = 0;
        int lev = 1;
        while (lev <= p - 1) {
            long long next = ((power(c, lev) % mod) * (dp[i - lev] % mod)) % mod;
            res = (res % mod + next % mod + mod) % mod;
            lev++;
        }
        dp[i] = -res % mod;
    }
    cout << abs(dp[k]) << '\n';
    cout << (dp[k] > 0 ? dp[k] : dp[k] + mod);
    return 0;
}