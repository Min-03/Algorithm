#include <bits/stdc++.h>
using namespace std;

char graph[20][20];
bool used[26];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, cnt = 0;

void go(int x, int y, int depth) {
    used[graph[x][y] - 'A'] = true;
    cnt = max(cnt, depth);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c && !used[graph[nx][ny] - 'A']) {
            go(nx, ny, depth + 1);
        }
    }
    used[graph[x][y] - 'A'] = false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> graph[i];
    }
    go(0, 0, 1);
    cout << cnt;
    return 0;
}