#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1001][1001];
int dir[1001][1001];
string a, b;

void printAns(int i, int j) {
    if (i == 0 || j == 0) return;
    if (dir[i][j] == 1) {
        printAns(i - 1, j - 1);
        cout << a[i];
    } else if (dir[i][j] == 2) {
        printAns(i - 1, j);
    } else {
        printAns(i, j - 1);
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
                dir[i][j] = 1;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                dir[i][j] = 2;
            } else {
                dp[i][j] = dp[i][j - 1];
                dir[i][j] = 3;
            }
        }
    }
    cout << dp[a.length() - 1][b.length() - 1] << '\n';
    if (dp[a.length() - 1][b.length() - 1] == 0) return 0;
    printAns(a.length() - 1, b.length() - 1);
    return 0;
}