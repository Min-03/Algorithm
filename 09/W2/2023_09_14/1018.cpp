#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[50][50];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    int ans = 1e9;
    for (int i = 0; i + 7 < n; i++) {
        for (int j = 0; j + 7 < m; j++) {
            //맨 위 흰색
            int curr = 0, cnt = 0;
            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((curr & 1) && graph[x][y] != 'B') cnt++;
                    if (!(curr & 1) && graph[x][y] != 'W') cnt++;
                    if (y != j + 7) curr++;
                }
            }
            ans = min(ans, cnt);
            curr = cnt = 0;
            //맨 위 검은색
            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((curr & 1) && graph[x][y] != 'W') cnt++;
                    if (!(curr & 1) && graph[x][y] != 'B') cnt++;
                    if (y != j + 7) curr++;
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}