#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[10][10];
bool visited[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans = 0;
int n, m;

void dfs(int x, int y, int until) {
    if (x == n - 1 && y == m - 1) {
        ans = max(ans, until);
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
            dfs(nx, ny, until + graph[nx][ny]);
        }
    }
    visited[x][y] = false;

}

int main() {
    FastIO
    for (int k = 0; k < 36; k++) {
        int x = k / 6;
        int y = k % 6;
        ans = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                graph[i][j] = 1000;
            }
        }
        graph[x][y] = 1;
        n = m = 6;
        dfs(0, 0, graph[0][0]);
//        cout << ans << endl;
        if (ans == 34001) cout << x << ' ' << y << endl;
    }

    return 0;
}