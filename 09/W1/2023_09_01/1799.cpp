#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool upDown[21], check[10][10];
int ansBlack = 0, ansWhite = 0;
int n;

//curr : 몇 번 인덱스의 downUp 대각선인지(x + y = curr)
void go(int curr, int cnt, bool isBlack) {
    if (curr >= 2 * n - 1) {
        if (isBlack) ansBlack = max(ansBlack, cnt);
        else ansWhite = max(ansWhite, cnt);
        return;
    }
    if (isBlack && ansBlack >= 2 * n - 1 - curr + cnt) return;
    if (!isBlack && ansWhite >= 2 * n - 1 - curr + cnt) return;

    for (int x = max(0, curr - n + 1); x <= min(curr, n - 1); x++) {
        int y = curr - x;
        assert(0 <= x && x <= n - 1 && 0 <= y && y <= n - 1);
        if (check[x][y] && !upDown[x - y + n - 1]) {
            upDown[x - y + n - 1] = true;
            go(curr + 2, cnt + 1, isBlack);
            upDown[x - y + n - 1] = false;
        }
    }
    go(curr + 2, cnt, isBlack);
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> check[i][j];
        }
    }
    go(0, 0, true);
    go(1, 0, false);
    cout << ansBlack + ansWhite;
    return 0;
}