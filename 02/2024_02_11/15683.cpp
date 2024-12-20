#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[8][8], temp[8][8];
vector<pair<int, int>> cctvs;
vector<int> add[6];
int type[8], dir[8];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, ans = 100;

void spread() {
    for (int i = 0; i < cctvs.size(); i++) {
        auto [sx, sy] = cctvs[i];
        for (int pDir : add[type[i]]) {
            int x = sx;
            int y = sy;
            int d = (dir[i] + pDir) % 4;
            while (0 <= x && x < n && 0 <= y && y < m && temp[x][y] != 6) {
                temp[x][y] = type[i];
                x += dx[d];
                y += dy[d];
            }
        }
    }
}

void go(int curr) {
    if (curr == cctvs.size()) {
        memcpy(temp, graph, sizeof(graph));
        spread();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    if (type[curr] == 5) {
        dir[curr] = 0;
        go(curr + 1);
        return;
    } else if (type[curr] == 2) {
        dir[curr] = 0;
        go(curr + 1);
        dir[curr] = 1;
        go(curr + 1);
        return;
    }

    for (int i = 0; i < 4; i++) {
        dir[curr] = i;
        go(curr + 1);
    }
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 0 && graph[i][j] != 6) {
                cctvs.push_back({i, j});
                type[cctvs.size() - 1] = graph[i][j];
            }
        }
    }
    for (int i = 1; i <= 5; i++) add[i].push_back(0);
    for (int i : {3, 4, 5}) add[i].push_back(1);
    for (int i : {2, 4, 5}) add[i].push_back(2);
    add[5].push_back(3);
    go(0);
    cout << ans;
    return 0;
}