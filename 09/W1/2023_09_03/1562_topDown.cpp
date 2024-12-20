#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int mod = 1e9;

long long dp[101][10][1 << 10];

//원래 방식대로 하나씩 제거
long long go(int len, int last, int set) {
    if (len == 1) {
        set &= ~(1 << last);
        if (set == 0) {
            if (last == 0) return 0;
            else return 1;
        } else {
            return 0;
        }
    }

    if (dp[len][last][set] != -1) {
        return dp[len][last][set];
    }

    long long ret = 0;
    if (last > 0) ret += go(len - 1, last - 1, set & ~(1 << last));
    if (last < 9) ret += go(len - 1, last + 1, set & ~(1 << last));
    ret %= mod;
    return dp[len][last][set] = ret;
}

int main() {
    FastIO
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += go(n, i, (1 << 10) - 1);
        ans %= mod;
    }
    cout << ans;
    return 0;
}