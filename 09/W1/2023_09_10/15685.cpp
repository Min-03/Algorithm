#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool used[101][101];
vector<int> paths[11]; //gen이 i인 커브의 경로, 시작 방향 0 기준
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void setCurves(int x, int y, int gen, int dir) {
    used[x][y] = true;
    for (int i = 0; i < paths[gen].size(); i++) {
        int currDir = paths[gen][i];
        x += dx[(currDir + dir) % 4];
        y += dy[(currDir + dir) % 4];
        used[x][y] = true;
    }
}

int main() {
    FastIO
    paths[0] = {0};
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < paths[i - 1].size(); j++) {
            paths[i].push_back(paths[i - 1][j]);
        }
        for (int j = paths[i - 1].size() - 1; j >= 0; j--) {
            paths[i].push_back((paths[i - 1][j] + 1) % 4);
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        setCurves(y, x, g, d);
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (used[i][j] && used[i + 1][j] && used[i][j + 1] && used[i + 1][j + 1]) ans++;
        }
    }
    cout << ans;
    return 0;
}