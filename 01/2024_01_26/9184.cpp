#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dp[101][101][101];

int go(int x, int y, int z) {
    if (x <= 50 || y <= 50 || z <= 50) return 1;
    if (dp[x][y][z] != inf) return dp[x][y][z];
    if (x > 70 || y > 70 || z > 70) return dp[x][y][z] = go(70, 70, 70);
    if (x < y && y < z) {
        return dp[x][y][z] = go(x, y, z - 1) + go(x, y - 1, z - 1) - go(x, y - 1, z);
    } else {
        return dp[x][y][z] = go(x - 1, y, z) + go(x - 1, y - 1, z) + go(x - 1, y, z - 1) - go(x - 1, y - 1, z - 1);
    }

}

int main() {
    FastIO
    memset(dp, inf, sizeof(dp));
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b && b == c && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, go(a + 50, b + 50, c + 50));
    }
    return 0;
}