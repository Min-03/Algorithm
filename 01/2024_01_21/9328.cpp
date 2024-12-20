#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool visited[100][100];
char graph[100][100];
vector<pair<int, int>> doors[26];
bool allowed[26];
int dx[] = {1, -1, 0 ,0};
int dy[] = {0, 0, 1, -1};
int h, w;

int bfs(int sx, int sy) {
    visited[sx][sy] = true;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    int ret = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (graph[x][y] == '$') {
            ret++;
        } else if (islower(graph[x][y])) {
            int idx = graph[x][y] - 'a';
            allowed[idx] = true;
            for (auto [nx, ny] : doors[idx]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        } else if (isupper(graph[x][y])) {
            int idx = graph[x][y] - 'A';
            doors[idx].push_back({x, y});
            if (!allowed[idx]) continue;

        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny] || graph[nx][ny] == '*') continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return ret;
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        string keys;
        cin >> h >> w;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 26; i++) doors[i].clear();
        for (int i = 0; i < 26; i++) allowed[i] = false;
        for (int i = 0; i < h; i++) cin >> graph[i];
        cin >> keys;

        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j : {0, w - 1}) {
                if (!visited[i][j] && graph[i][j] != '*') {
                    ans += bfs(i, j);
                }
            }
        }
        for (int j = 0; j < w; j++) {
            for (int i : {0, h - 1}) {
                if (!visited[i][j] && graph[i][j] != '*') ans += bfs(i, j);
            }
        }

        for (char key : keys) {
            if (key == '0') break;
            int idx = key - 'a';
            allowed[idx] = true;
            for (auto [nx, ny] : doors[idx]) {
                ans += bfs(nx, ny);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}