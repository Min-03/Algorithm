#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[1000][1000];
int group[1000][1000];
int groupSize[1'000'001];
bool visited[1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

int groupNums(int x, int y, int color) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    group[x][y] = color;
    int ret = 0;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        ret++;
        group[x][y] = color;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && graph[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return ret;
}

int main() {
    FastIO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    int color = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                color++;
                groupSize[color] = groupNums(i, j, color);
            }
        }
    }

    int ans = 0;
    //0의 입장에서 바라보자!
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                int res = 1;
                set<int> visitedGroup;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && graph[nx][ny] == 1) {
                        int gp = group[nx][ny];
                        if (visitedGroup.find(gp) != visitedGroup.end()) continue;
                        res += groupSize[gp];
                        visitedGroup.insert(gp);
                    }
                }
                ans = max(ans, res);
            }
        }
    }
    cout << ans;
    return 0;
}