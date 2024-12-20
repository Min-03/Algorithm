#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int visited[200][200];
int n;

int bfs(int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> q;
    visited[startX][startY] = 0;
    q.emplace(startX, startY);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == endX && y == endY) {
            return visited[x][y];
        }
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && (visited[nx][ny] == -1)) {
                visited[nx][ny] = visited[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    memset(visited, -1, sizeof(visited));
    cout << bfs(r1, c1, r2, c2);
    return 0;
}