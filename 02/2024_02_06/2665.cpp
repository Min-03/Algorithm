#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dist[50][50];
bool isWhite[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

int bfs() {
    memset(dist, inf, sizeof(dist));
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            int nDist = dist[x][y] + (!isWhite[nx][ny]);
            if (nDist < dist[nx][ny]) {
                q.push({nx, ny});
                dist[nx][ny] = nDist;
            }
        }
    }
    return dist[n - 1][n - 1];
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            isWhite[i][j] = (str[j] == '1');
        }
    }
    cout << bfs();
    return 0;
}