#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const long long mod = 1e9 + 7;

long long power(long long a, int b) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret = (ret * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    FastIO
    int m;
    cin >> m;
    long long ans = 0;
    while (m--) {
        long long n, s;
        cin >> n >> s;
        ans += ((s % mod) * power(n, mod - 2)) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}