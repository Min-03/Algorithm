#include <bits/stdc++.h>
using namespace std;

int graph[500][500];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[500][500];
int n, m;

int dfs(int x, int y, int depth, int curr) {
    visited[x][y] = true;
    if (depth == 4) {
        visited[x][y] = false;
        return curr;
    }
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (!visited[nx][ny]) {
                res = max(res, dfs(nx, ny, depth + 1, curr + graph[nx][ny]));
            }
        }
    }
    visited[x][y] = false;
    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int ans = 0;
    //ㅗ, ㅜ, ㅏ, ㅓ 모양을 제외한 나머지
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(i, j, 1, graph[i][j]));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int curr;
            //ㅗ, ㅜ 모양
            if (j < m - 2) {
                curr = graph[i][j + 1] + graph[i][j + 2] + graph[i][j];
                if (i < n - 1) {
                    ans = max(ans, curr + graph[i + 1][j + 1]);
                }
                if (i > 0) {
                    ans = max(ans, curr + graph[i - 1][j + 1]);
                }
            }
            //ㅏ, ㅓ 모양
            if (i < n - 2) {
                curr = graph[i][j] + graph[i + 1][j] + graph[i + 2][j];
                if (j < m - 1) {
                    ans = max(ans, curr + graph[i + 1][j + 1]);
                }
                if (j > 0) {
                    ans = max(ans, curr + graph[i + 1][j - 1]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
