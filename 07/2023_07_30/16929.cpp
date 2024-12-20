#include <bits/stdc++.h>
using namespace std;

char graph[50][50];
bool visited[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool isCycle(int x, int y, int preX, int preY) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && (nx != preX || ny != preY) && graph[x][y] == graph[nx][ny]) {
            if (visited[nx][ny]) {
                return true;
            } else {
                if (isCycle(nx, ny, x, y)) return true;
            }
        }
    }
    return false;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string charStr;
        cin >> charStr;
        for (int j = 0; j < m; j++) {
            graph[i][j] = charStr[j];
        }
    }

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && isCycle(i, j, -1, -1)) {
                hasCycle = true;
                break;
            }
        }
        if (hasCycle) break;
    }
    cout << (hasCycle ? "Yes" : "No");
    return 0;
}