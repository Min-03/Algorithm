#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[16][16];
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};
int n, ans = 0;

// 0 : 세로, 1 : 가로, 2 : 대각선
void dfs(int x, int y, int prevDir) {
    if (x == n - 1 && y == n - 1) {
//        cout << prevDir << endl;
        ans += 1;
    }
//    cout << x << ' ' << y << ' ' << prevDir << endl;
    for (int i = 0; i < 3; i++) {
        //가로 다음 세로, 세로 다음 가로는 불가능
        if (prevDir != 2 && prevDir + i == 1) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && graph[nx][ny] == 0) {
            if (i == 2 && (graph[nx][ny - 1] == 1 || graph[nx - 1][ny] == 1)) continue;
            dfs(nx, ny, i);
        }
    }
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    dfs(0, 1, 1);
    cout << ans;
    return 0;
}
