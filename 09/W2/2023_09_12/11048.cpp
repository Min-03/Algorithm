#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int candies[1000][1000];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> candies[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int add = 0;
            if (i != 0) add = max(add, candies[i - 1][j]);
            if (j != 0) add = max(add, candies[i][j - 1]);
            if (i != 0 && j != 0) add = max(add, candies[i - 1][j - 1]);
            candies[i][j] += add;
        }
    }
    cout << candies[n - 1][m - 1];
    return 0;
}