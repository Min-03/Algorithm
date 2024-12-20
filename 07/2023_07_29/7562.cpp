#include <bits/stdc++.h>
using namespace std;
int visited[300][300];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int l, startX, startY, endX, endY;
int bfs(int x, int y) {
    queue<tuple<int, int, int>> q;
    q.emplace(x, y, 0);
    visited[x][y] = true;
    while (!q.empty()) {
        int currX = get <0> (q.front());
        int currY = get <1> (q.front());
        int cnt = get <2> (q.front());
        q.pop();
        if (currX == endX && currY == endY) {
            return cnt;
        }
        for (int i = 0; i < 8; i++) {
            int nx = currX + dx[i];
            int ny = currY + dy[i];
            if (0 <= nx && nx < l && 0 <= ny && ny < l && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.emplace(nx, ny, cnt + 1);
            }
        }
    }
    return -1;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> l >> startX >> startY >> endX >> endY;
        int cnt = bfs(startX, startY);
        cout << cnt << '\n';
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
