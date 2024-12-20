#include <bits/stdc++.h>
using namespace std;

char graph[20][20];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, cnt = 0;
char choose[400];

void go(int x, int y, int depth) {
    choose[depth - 1] = graph[x][y];
    cnt = max(cnt, depth);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c && find(choose, choose + depth, graph[nx][ny]) == choose + depth) {
            go(nx, ny, depth + 1);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }
    go(0, 0, 1);
    cout << cnt;
    return 0;
}
