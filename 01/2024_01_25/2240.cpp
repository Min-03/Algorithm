#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1000][31][2];
int num[1000];
int t, w;

int go(int time, int left, int p) {
    if (time >= t) return 0;
    if (dp[time][left][p] != -1) return dp[time][left][p];
    int ret = go(time + 1, left, p);
    if (left != 0) ret = max(ret, go(time + 1, left - 1, p ^ 1));
    if (p == num[time]) ret++;
    return dp[time][left][p] = ret;
}

int main() {
    FastIO
    cin >> t >> w;
    for (int i = 0; i < t; i++) {
        cin >> num[i];
        num[i]--;
    }
    memset(dp, -1, sizeof(dp));
    cout << max(go(0, w, 0), go(0, w - 1, 1));
    return 0;
}