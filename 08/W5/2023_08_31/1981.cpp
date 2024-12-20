#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[100][100];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

bool bfs(int lo, int hi) {
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == n - 1 && y == n - 1) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                int num = graph[nx][ny];
                visited[nx][ny] = true;
                if (lo <= num && num <= hi) {
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

bool check(int num) {
    int lo = 0, hi = num;
    while (hi <= 200) {
        memset(visited, 0, sizeof(visited));
        if (lo <= graph[0][0] && graph[0][0] <= hi && bfs(lo, hi)) return true;
        lo++, hi++;
    }
    return false;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int lo = -1, hi = 200;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}