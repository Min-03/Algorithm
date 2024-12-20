#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

int graph[8][8];
int temp[8][8];
bool visited[8][8];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0,  1, -1};
int n, m;

bool isEmpty(int num) {
    int x = num / m;
    int y = num % m;
    return graph[x][y] == 0;
}

void setWall(int num, bool open) {
    int x = num / m;
    int y = num % m;
    if (open) graph[x][y] = 1;
    else graph[x][y] = 0;
}

void spreadVir(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = true;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}

int countSafe(int x, int y) {
    int ret = 0;
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.emplace(x, y);
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        ret += 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && temp[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
    return ret;
}

int go() {
    memset(visited, 0, sizeof(visited));
    memcpy(temp, graph, sizeof(graph));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && temp[i][j] == 2) {
                spreadVir(i, j);
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && temp[i][j] == 0) {
                ret += countSafe(i, j);
            }
        }
    }
    return ret;
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        if (!isEmpty(i)) continue;
        setWall(i, true);
        for (int j = i + 1; j < n * m; j++) {
            if (!isEmpty(j)) continue;
            setWall(j, true);
            for (int k = j + 1; k < n * m; k++) {
                if (!isEmpty(k)) continue;
                setWall(k, true);
                ans = max(ans, go());
                setWall(k, false);
            }
            setWall(j, false);
        }
        setWall(i, false);
    }
    cout << ans;
    return 0;
}
