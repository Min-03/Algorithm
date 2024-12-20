#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[8][8];
bool visited[8][8][30];
int dx[] = {1, -1, 0, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 0, 1, -1, 1, -1};

bool check(int x, int y) {
    return 0 <= x && x < 8 && 0 <= y && y < 8;
}

bool isWall(int x, int y, int sec) {
    if (check(x - sec, y) && graph[x - sec][y] == '#') {
        return true;
    }
    else return false;
}

bool bfs() {
    visited[7][0][0] = true;
    queue<tuple<int, int, int>> q;
    q.push({7, 0, 0});
    while (!q.empty()) {
        int x, y, sec;
        int qSize = q.size();
        while (qSize--) {
            tie(x, y, sec) = q.front(); q.pop();
            if (isWall(x, y, sec)) {
                continue;
            }
            if (x == 0 && y == 7) {
                return true;
            }
            for (int i = 0; i < 9; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx, ny) && !visited[nx][ny][sec + 1] && !isWall(nx, ny, sec)) {
                    visited[nx][ny][sec + 1] = true;
                    q.push({nx, ny, sec + 1});
                }
            }
        }
    }
    return false;
}

int main() {
    FastIO
    for (int i = 0; i < 8; i++) {
        cin >> graph[i];
    }
    cout << (bfs() ? 1 : 0);
    return 0;
}
