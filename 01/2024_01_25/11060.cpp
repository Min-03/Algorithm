#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dp[1000], a[1000];
int n;

int go(int x) {
    if (x > n - 1) {
        return inf;
    } else if (x == n - 1) {
        return 0;
    }
    if (dp[x] != -1) return dp[x];
    int ret = inf;
    for (int i = 1; i <= a[x]; i++) ret = min(ret, go(x + i));
    return dp[x] = ret + 1;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << (go(0) >= inf ? -1 : go(0));
    return 0;
}