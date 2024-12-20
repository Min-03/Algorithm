#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[100'001][5][5];
int cost[5][5];

void setCost(int start, int opposite) {
    for (int i = 0; i < 5; i++) {
        if (i == start) cost[start][i] = 1;
        else if (i == opposite) cost[start][opposite] = 4;
        else cost[start][i] = 3;
    }
}

int getCost(int l1, int r1, int l2, int r2) {
    if (l1 != l2) return cost[l1][l2];
    else return cost[r1][r2];
}

int main() {
    FastIO
    for (int i = 0; i < 5; i++) cost[0][i] = 2;
    setCost(1, 3);
    setCost(2, 4);
    setCost(3, 1);
    setCost(4, 2);
    for (int i = 0; i <= 100'000; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) dp[i][j][k] = 1e6;
        }
    }
    dp[0][0][0] = 0;
    int step = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        step++;
        //왼발 옮김
        for (int i = 0; i < 5; i++) {
            if (i == n) continue;
            //왼발 옮김
            for (int j = 0; j < 5; j++) {
                dp[step][n][i] = min(dp[step][n][i], dp[step - 1][j][i] + getCost(j, i, n, i));
            }
            //오른발 옮김
            for (int j = 0; j < 5; j++) {
                dp[step][n][i] = min(dp[step][n][i], dp[step - 1][n][j] + getCost(n, j, n, i));
            }
        }

        //오른발 옮김
        for (int i = 0; i < 5; i++) {
            if (i == n) continue;
            //왼발 옮김
            for (int j = 0; j < 5; j++) {
                dp[step][i][n] = min(dp[step][i][n], dp[step - 1][j][n] + getCost(j, n, i, n));
            }
            //오른발 옮김
            for (int j = 0; j < 5; j++) {
                dp[step][i][n] = min(dp[step][i][n], dp[step - 1][i][j] + getCost(i, j, i, n));
            }
        }
    }
    int lo = 1e6;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) lo = min(lo, dp[step][i][j]);
    }
    cout << lo;
    return 0;
}