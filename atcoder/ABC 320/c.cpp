#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string s1, s2, s3;
    int m, ans = 1e9;
    cin >> m >> s1 >> s2 >> s3;
    for (int i = 0; i <= 3 * m; i++) {
        for (int j = 0; j <= 3 * m; j++) {
            for (int k = 0; k <= 3 * m; k++) {
                if (i == j || j == k || i == k) continue;
                if (s1[i % m] == s2[j % m] && s2[j % m] == s3[k % m]) {
                    ans = min(ans, max({i, j, k}));
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}