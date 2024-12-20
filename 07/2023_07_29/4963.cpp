#include <bits/stdc++.h>
using namespace std;
int graph[50][50];
int visited[50][50];
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
int w, h;
void bfs(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int>> queue;
    queue.push(make_pair(x, y));
    while (!queue.empty()) {
        int currX = queue.front().first;
        int currY = queue.front().second;
        queue.pop();
        for (int i = 0; i < 8; i++) {
            int nx = currX + dx[i];
            int ny = currY + dy[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && graph[nx][ny] == 1 && !visited[nx][ny]) {
                queue.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> graph[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (graph[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        //초기화
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
    }
}