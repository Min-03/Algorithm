#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isOne[1001][1001];
int contiHor[1001][1001], contiVer[1001][1001], dp[1001][1001];
int n, m;

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            if (str[j - 1] == '1') isOne[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cnt++;
            if (!isOne[i][j]) cnt = 0;
            contiHor[i][j] = cnt;
        }
    }
    for (int j = 1; j <= m; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt++;
            if (!isOne[i][j]) cnt = 0;
            contiVer[i][j] = cnt;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min({contiVer[i][j], contiHor[i][j], dp[i - 1][j - 1] + 1});
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans * ans;
    return 0;
}