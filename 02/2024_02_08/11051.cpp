#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int mod = 1e4 + 7;

long long power(long long a, int b) {
    long long ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ret % mod * a % mod) % mod;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    FastIO
    int n, k, res = 1;
    cin >> n >> k;
    for (int i = k + 1; i <= n; i++) {
        res *= i;
        res %= mod;
        res *= power(n - i + 1, mod - 2);
        res %= mod;
    }
    cout << res;
    return 0;
}