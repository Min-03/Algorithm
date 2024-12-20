#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int mod = 1234567891;
const int r = 31;

long long power(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    int l;
    long long ans = 0;
    cin >> l;
    for (int i = 0; i < l; i++) {
        char ch;
        cin >> ch;
        ans += (ch - 'a' + 1) * (power(r, i));
        ans %= mod;
    }
    cout << ans;
}