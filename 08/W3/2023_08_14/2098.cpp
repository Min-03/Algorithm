#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1 << 16][16]; // dp[set][last]
int costs[16][16];
int n;

//0번째 도시에서 시작해서 set에 있는 도시를 순회 할 때의 최소 비용, 불가능하면 -1 반환
int go(int set, int last, int length) {
    if (length == 2) {
        if (costs[0][last] == 0) return -1;
        else return costs[0][last];
    }
    if (dp[set][last] != 0) {
        return dp[set][last];
    }

    set &= ~(1 << last);
    int ret = -1;
    //i - last 순으로 순회
    for (int i = 1; i < n; i++) {
        if ((set & (1 << i)) && costs[i][last] != 0) {
            dp[set][i] = go(set, i, length - 1);
            if (dp[set][i] != -1 && (ret == -1 || ret > dp[set][i] + costs[i][last])) {
                ret = dp[set][i] + costs[i][last];
            }
        }
    }
    return ret;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costs[i][j];
        }
    }
    int ans = -1;
    //i를 마지막으로 해서 순회
    for (int i = 1; i < n; i++) {
        if (costs[i][0] == 0) continue;
        int res = go((1 << n) - 1, i, n);
        if (res != -1 && (ans == -1 || ans > res + costs[i][0])) {
            ans = res + costs[i][0];
        }
    }
    cout << ans;
    return 0;
}