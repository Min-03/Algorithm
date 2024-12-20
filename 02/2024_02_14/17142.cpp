#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int graph[50][50];
int dist[50][50];
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
bool choose[10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, ans = inf;

void bfs() {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] != inf || graph[nx][ny] == 1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

void go(int curr, int chooseNum) {
    if (chooseNum > m) return;
    if (curr == virus.size()) {
        if (chooseNum != m) return;
        memset(dist, inf, sizeof(dist));
        //활성화된 바이러스 bfs
        for (int i = 0; i < virus.size(); i++) {
            if (choose[i]) {
                auto [x, y] = virus[i];
                dist[x][y] = 0;
                q.push({x, y});
            }
        }
        bfs();
        int res = 0;
        //최소 시간 계산
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 0) res = max(res, dist[i][j]);
            }
        }
        ans = min(ans, res);
        return;
    }
    choose[curr] = true;
    go(curr + 1, chooseNum + 1);
    choose[curr] = false;
    go(curr + 1, chooseNum);
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }
    go(0, 0);
    cout << (ans == inf ? -1 : ans);
    return 0;
}