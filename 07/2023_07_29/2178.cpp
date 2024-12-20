#include <bits/stdc++.h>
using namespace std;
int graph[100][100];
int visited[100][100];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int bfs(int x, int y) {
    queue<tuple<int, int, int>> queue;
    queue.emplace(x, y, 1);
    visited[x][y] = true;
    while (!queue.empty()) {
        int currX = get<0> (queue.front());
        int currY = get<1> (queue.front());
        int length = get<2> (queue.front());
        if (currX == n - 1 && currY == m - 1) {
            return length;
        }
        queue.pop();
        for (int i = 0; i < 4; i++) {
            int nx = currX + dx[i];
            int ny = currY + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && graph[nx][ny] == 1 && !visited[nx][ny]) {
                queue.emplace(nx, ny, length + 1);
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < m; j++) {
            graph[i][j] = numStr[j] - '0';
        }
    }
    int length = bfs(0, 0);
    cout << length;
    return 0;
}