#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[6][6];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

bool sol() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 'T') q.push({i, j});
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (0 <= nx && nx < n && 0 <= ny && ny < n && graph[nx][ny] != 'O') {
                if (graph[nx][ny] == 'S') {
                    return false;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    return true;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n * n; i++) {
        int x1 = i / n, y1 = i % n;
        if (graph[x1][y1] != 'X') continue;
        graph[x1][y1] = 'O';
        for (int j = i + 1; j < n * n; j++) {
            int x2 = j / n, y2 = j % n;
            if (graph[x2][y2] != 'X') continue;
            graph[x2][y2] = 'O';
            for (int k = j + 1; k < n * n; k++) {
                int x3 = k / n, y3 = k % n;
                if (graph[x3][y3] != 'X') continue;
                graph[x3][y3] = 'O';
                if (sol()) {
                    cout << "YES";
                    return 0;
                }
                graph[x3][y3] = 'X';
            }
            graph[x2][y2] = 'X';
        }
        graph[x1][y1] = 'X';
    }
    cout << "NO";
    return 0;
}