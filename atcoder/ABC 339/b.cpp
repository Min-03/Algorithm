#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int h, w, n;

int main() {
    FastIO
    cin >> h >> w >> n;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) graph[i][j] = '.';
    }
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while (n--) {
        auto [x, y, dir] = q.front(); q.pop();
        int nDir;
        if (graph[x][y] == '.') {
            graph[x][y] = '#';
            nDir = (dir + 1) % 4;
        } else {
            graph[x][y] = '.';
            nDir = (dir - 1 + 4) % 4;
        }
        int nx = (x + dx[nDir] + h) % h;
        int ny = (y + dy[nDir] + w) % w;
        q.push({nx, ny, nDir});
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << graph[i][j];
        cout << '\n';
    }
    return 0;
}