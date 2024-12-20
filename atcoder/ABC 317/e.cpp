#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[2000][2000];
int cnts[2000][2000];
int dx[] =  {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int h, w;

bool check(int x, int y) {
    return 0 <= x && x < h && 0 <= y && y < w && cnts[x][y] == -1;
}

void fillGraph(char ch, int x, int y) {
    if ((graph[x][y] != '.' && graph[x][y] != '!') || !check(x, y)) return;
    if (ch == '^') {
        graph[x][y] = '!';
        fillGraph(ch, x - 1, y);
    } else if (ch == '>') {
        graph[x][y] = '!';
        fillGraph(ch, x, y + 1);
    } else if (ch == '<') {
        graph[x][y] = '!';
        fillGraph(ch, x, y - 1);
    } else {
        graph[x][y] = '!';
        fillGraph(ch, x + 1, y);
    }
}

int bfs(int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    cnts[sx][sy] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == ex && y == ey) {
            return cnts[x][y];
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((graph[nx][ny] == '.' || graph[nx][ny] == 'G') && check(nx, ny)) {
                cnts[nx][ny] = cnts[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    FastIO
    cin >> h >> w;
    vector<pair<char, pair<int, int>>> sights;
    sights.reserve(w * h);
    int sx, sy, ex, ey;
    sx = sy = ex = ey = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == '<' || graph[i][j] == '>' || graph[i][j] == '^' || graph[i][j] == 'v') {
                sights.push_back({graph[i][j], {i, j}});
            } else if (graph[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (graph[i][j] == 'G') {
                ex = i;
                ey = j;
            }
        }
    }
    memset(cnts, -1, sizeof(cnts));
    for (auto [ch, pair] : sights) {
        auto [x, y] = pair;
        if (ch == '^') {
            fillGraph(ch, x - 1, y);
        } else if (ch == '>') {
            fillGraph(ch, x, y + 1);
        } else if (ch == '<') {
            fillGraph(ch, x, y - 1);
        } else {
            fillGraph(ch, x + 1, y);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << graph[i][j] << " \n"[j == w - 1];
        }
    }
    cout << bfs(sx, sy, ex, ey);
    return 0;
}