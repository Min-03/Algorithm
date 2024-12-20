#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> clouds;
int graph[50][50];
bool wasCloud[50][50];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n, m;

pair<int, int> getNext(int x, int y, int d, int s) {
    d--;
    int nx = (x + s * dx[d] + 50 * n) % n;
    int ny = (y + s * dy[d] + 50 * n) % n;
    return {nx, ny};
}

int getCnt(int x, int y) {
    int ret = 0;
    for (int i : {1, 3, 5, 7}) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && graph[nx][ny]) ret++;
    }
    return ret;
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }
    for (int i : {n - 2, n - 1}) {
        for (int j : {0, 1}) clouds.push_back({i, j});
    }
    while (m--) {
        memset(wasCloud, 0, sizeof(wasCloud));
        int d, s;
        cin >> d >> s;
        //구름 이동 & 구름 위치 기록
        for (int i = 0; i < clouds.size(); i++) {
            auto [x, y] = clouds[i];
            auto [nx, ny] = getNext(x, y, d, s);
            clouds[i] = {nx, ny};
            wasCloud[nx][ny] = true;
        }
        //비 내림
        for (auto [x, y] : clouds) {
            graph[x][y]++;
        }
        //물복사 버그
        for (auto [x, y] : clouds) {
            graph[x][y] += getCnt(x, y);
        }
        //구름 초기화
        clouds.clear();
        //구름 생성 & 물 줄이기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] < 2 || wasCloud[i][j]) continue;
                graph[i][j] -= 2;
                clouds.push_back({i, j});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) ans += graph[i][j];
    }
    cout << ans;
    return 0;
}