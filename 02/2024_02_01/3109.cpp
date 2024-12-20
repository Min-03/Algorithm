#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[10'000][500];
bool visited[10'000][500];
int r, c;

bool dfs(int x, int y) {
    if (y == c - 1) return true;
    visited[x][y] = true;
    int ny = y + 1;
    for (int nx : {x - 1, x, x + 1}) {
        if (nx < 0 || nx >= r || visited[nx][ny] || graph[nx][ny] == 'x') continue;
        if (dfs(nx, ny)) return true;
    }
    return false;
}

int main() {
    FastIO
    cin >> r >> c;
    int cnt = 0;
    for (int i = 0; i < r; i++) cin >> graph[i];
    for (int i = 0; i < r; i++) {
        if (dfs(i, 0)) cnt++;
    }
    cout << cnt;
    return 0;
}