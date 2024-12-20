#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long k;
long long dp[100][10];

void printNum(int first, int digit, int left) {
    if (digit == 0) return;
    cout << first;
    for (int i = 0; i <= 9; i++) {
        left -= dp[digit - 1][i];
        if (left <= 0) {
            printNum(i, digit - 1, left + dp[digit - 1][i]);
            return;
        }
    }
}

int main() {
    FastIO
    cin >> k;
    if (k <= 9) {
        cout << k;
        return 0;
    }
    k++;
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }
    k -= 10;
    int len = 2;
    while (true) {
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < i; j++) {
                dp[len][i] += dp[len - 1][j];
            }
            k -= dp[len][i];
            if (k <= 0) {
                k += dp[len][i];
                printNum(i, len, k);
                return 0;
            }
        }
        len++;
    }
}