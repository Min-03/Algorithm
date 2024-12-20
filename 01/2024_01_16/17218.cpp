#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[41][41];
int dir[41][41]; // 1: 위, 2: 왼쪽, 3: 대각선
string a, b;

void printAns(int x, int y) {
    if (x == 0 || y == 0) return;
    if (dir[x][y] == 1) {
        printAns(x - 1, y);
    } else if (dir[x][y] == 2) {
        printAns(x, y - 1);
    } else {
        printAns(x - 1, y - 1);
        cout << a[x];
    }
}

int main() {
    FastIO
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    for (int i = 1; i < a.length(); i++) {
        for (int j = 1; j < b.length(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 3;
                continue;
            }
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                dir[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1];
                dir[i][j] = 2;
            }
        }
    }
    printAns(a.length() - 1, b.length() - 1);
    return 0;
}