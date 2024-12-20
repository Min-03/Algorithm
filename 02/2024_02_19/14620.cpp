#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[10][10];
bool selected[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

int getCost(int x, int y) {
    int ret = graph[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || selected[nx][ny]) return -1;
        ret += graph[nx][ny];
    }
    return ret;
}

void choose(int x, int y, bool isStart) {
    selected[x][y] = isStart;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        selected[nx][ny] = isStart;
    }
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }
    int ans = 1e8;
    for (int i = 0; i < n * n; i++) {
        int cost1 = getCost(i / n, i % n);
        if (cost1 == -1) continue;
        choose(i / n, i % n, true);
        for (int j = i + 1; j < n * n; j++) {
            int cost2 = getCost(j / n, j % n);
            if (cost2 == -1) continue;
            choose(j / n, j % n, true);
            for (int k = j + 1; k < n * n; k++) {
                int cost3 = getCost(k / n, k % n);
                if (cost3 == -1) continue;
                ans = min(ans, cost1 + cost2 + cost3);
            }
            choose(j / n, j % n, false);
        }
        choose(i / n, i % n, false);
    }
    cout << ans;
    return 0;
}