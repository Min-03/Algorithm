#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dists[10][10][7][2];
bool isLand[10][10];
int color[10][10];
int parents[7], ranks[7];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, cnt = 0;

void bfs(int type) {
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (color[i][j] == type) {
                for (int k = 0; k < 2; k++) {
                    q.push({i, j, k});
                    dists[i][j][type][k] = 0;
                }
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, dir] = q.front(); q.pop();
        for (int i : {2 * dir, 2 * dir + 1}) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dists[nx][ny][type][dir] != -1 || isLand[nx][ny]) continue;
            dists[nx][ny][type][dir] = dists[x][y][type][dir] + 1;
            q.push({nx, ny, dir});
        }

    }
}

void getGroup(int sx, int sy, int type) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    color[sx][sy] = type;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || !isLand[nx][ny] || color[nx][ny]) continue;
            color[nx][ny] = type;
            q.push({nx, ny});
        }
    }
}

int getCost(int a, int b) {
    int ret = 1e5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isLand[i][j]) continue;
            for (int dir = 0; dir < 2; dir++) {
                if (dists[i][j][a][dir] == -1 || dists[i][j][b][dir] == -1) continue;
                int len = dists[i][j][a][dir] + dists[i][j][b][dir] - 1;
                if (len != 1) ret = min(len, ret);
            }
        }
    }
    return ret;
}

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (ranks[a] > ranks[b]) swap(a, b);
    parents[a] = b;
    ranks[b] += ranks[a] == ranks[b];
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> isLand[i][j];
        }
    }
    memset(dists, -1, sizeof(dists));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isLand[i][j] && color[i][j] == 0) {
                getGroup(i, j, ++cnt);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) bfs(i);

    for (int i = 1; i <= cnt; i++) parents[i] = i;
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            edges.push_back({getCost(i, j), i, j});
        }
    }
    sort(edges.begin(), edges.end());
    int res = 0;
    for (auto [w, a, b] : edges) {
        if (find_set(a) != find_set(b)) {
            union_set(a, b);
            res += w;
        }
    }
    cout << (res >= 1e5 ? -1 : res);
    return 0;
}