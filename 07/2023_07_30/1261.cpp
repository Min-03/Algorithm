#include <bits/stdc++.h>
using namespace std;

int breaks[100][100];
int graph[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    breaks[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                int numBreak = (graph[nx][ny] == 1 ? breaks[x][y] + 1 : breaks[x][y]);
                if (breaks[nx][ny] == -1 || breaks[nx][ny] > numBreak) {
                    breaks[nx][ny] = numBreak;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < m; j++) {
            graph[i][j] = numStr[j] - '0';
        }
    }
    memset(breaks, -1, sizeof(breaks));
    bfs();
    cout << breaks[n - 1][m - 1];
    return 0;
}