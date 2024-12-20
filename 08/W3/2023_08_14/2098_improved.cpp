#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1 << 16][16];
int costs[16][16];
int n;

int go(int set, int curr) {
    if (set == (1 << n) - 1) {
        if (costs[curr][0] != 0) return costs[curr][0];
        else return -1;
    }

    if (dp[set][curr] != 0) {
        return dp[set][curr];
    }

    int ret = -1;
    for (int i = 1; i < n; i++) {
        if ((set & (1 << i)) || costs[curr][i] == 0) continue;
        int res = go(set | (1 << i), i);
        if (res != -1 && (ret == -1 || ret > res + costs[curr][i])) {
            ret = res + costs[curr][i];
        }
    }
    return dp[set][curr] = ret;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costs[i][j];
        }
    }
    cout << go(1, 0);
    return 0;
}