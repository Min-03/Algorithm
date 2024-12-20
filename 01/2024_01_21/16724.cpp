#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int orders[1000][1000];
char graph[1000][1000];
int cnt = 0;

void dfs(int x, int y, int order) {
    orders[x][y] = order;
    if (graph[x][y] == 'D') x++;
    else if (graph[x][y] == 'R') y++;
    else if (graph[x][y] == 'U') x--;
    else y--;
    if (orders[x][y] == 0) dfs(x, y, order);
    else if (orders[x][y] != order) cnt--;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    int color = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (orders[i][j] == 0) {
                dfs(i, j, color++);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}