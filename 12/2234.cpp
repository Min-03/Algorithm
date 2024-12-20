#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;

int types[50][50];
int sizes[50][50];
vector<pii> graph[50][50];

int bfs(int sx, int sy, int color) {
    queue<pii> q;
    vector<pii> v;
    q.push({sx, sy});
    types[sx][sy] = color;
    int size = 0;
    v.push_back({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        size++;
        for (auto [nx, ny] : graph[x][y]) {
            if (types[nx][ny] != 0) continue;
            q.push({nx, ny});
            types[nx][ny] = color;
            v.push_back({nx, ny});
        }
    }
    for (auto [x, y] : v) {
        sizes[x][y] = size;
    }
    return size;
}

int main() {
    FASTIO
    int n, m, type = 0, sizeOne = 0, sizeTwo = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int info;
            cin >> info;
            if (!((info >> 2) & 1) && j < m - 1) {
                graph[i][j].push_back({i, j + 1});
                graph[i][j + 1].push_back({i, j});
            }
            if (!((info >> 3) & 1) && i < n - 1) {
                graph[i][j].push_back({i + 1, j});
                graph[i + 1][j].push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (types[i][j] == 0) {
                sizeOne = max(sizeOne, bfs(i, j, ++type));
            }
        }
    }
    cout << type << '\n' << sizeOne << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n - 1 && types[i][j] != types[i + 1][j]) {
                int size = sizes[i][j] + sizes[i + 1][j];
                sizeTwo = max(sizeTwo, size);
            }
            if (j < m - 1 && types[i][j] != types[i][j + 1]) {
                int size = sizes[i][j] + sizes[i][j + 1];
                sizeTwo = max(sizeTwo, size);
            }
        }
    }
    cout << sizeTwo;
    return 0;
}