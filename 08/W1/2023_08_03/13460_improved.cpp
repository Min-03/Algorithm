#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

char graph[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, ans = -1;

bool check(pii ball, int i) {
    int nx = ball.first + dx[i];
    int ny = ball.second + dy[i];
    return 0 <= nx && nx < n && 0 <= ny && ny < m && graph[nx][ny] != '#';
}

void go(pii red, pii blue, int cnt, bool gaRoBefore) {
    if (cnt > 10 || (ans != -1 && cnt >= ans)) return;
    for (int i = 0; i < 4; i++) {
        if (cnt != 1) {
            if (gaRoBefore && dx[i] != 0) continue;
            else if (!gaRoBefore && dx[i] == 0) continue;
        }
        pii resB(blue), resR(red);
        int redCnt = 0, blueCnt = 0;
        bool stop = false;
        //파란 공 이동
        while (check(resB, i)) {
            blueCnt += 1;
            resB.first += dx[i];
            resB.second += dy[i];
            if (graph[resB.first][resB.second] == 'O') {
                stop = true;
                break;
            }
        }
        if (stop) {
            continue;
        }
        //빨간 공 이동
        while (check(resR, i)) {
            redCnt += 1;
            resR.first += dx[i];
            resR.second += dy[i];
            if (graph[resR.first][resR.second] == 'O') {
                if (ans == -1) {
                    ans = cnt;
                } else {
                    ans = min(ans, cnt);
                }
            }
        }
        if (resB.first == resR.first && resB.second == resR.second) {
            //파란 공이 더 많이 움직였으면, 파란 공이 빨간 공 뒤에 있었다는 뜻
            if (blueCnt > redCnt) {
                resB.first -= dx[i];
                resB.second -= dy[i];
            } else {
                resR.first -= dx[i];
                resR.second -= dy[i];
            }
        }
//        if (red.first == resR.first && red.second == resR.second && blue.first == resB.first && blue.second == resB.second) continue;
        go(resR, resB, cnt + 1, dx[i] != 0);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pii red, blue;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'R') {
                red.first = i;
                red.second = j;
            } else if (graph[i][j] == 'B') {
                blue.first = i;
                blue.second = j;
            }
        }
    }
    go(red, blue, 1, false);
    cout << ans;
    return 0;
}