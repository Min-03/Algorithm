#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
bool visited[20][20];
int graph[20][20];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, fishes = 0;

pair<int, pii> bfs(int x, int y, int size) {
    visited[x][y] = true;
    queue<pii> q;
    vector<pii> candidates;
    q.push({x, y});
    int ret = 0;
    while (!q.empty()) {
        int qSize = q.size();
        while (qSize--) {
            tie(x, y) = q.front(); q.pop();
            //먹을 수 있는 후보군에 올림
            if (graph[x][y] != 0 && graph[x][y] < size) {
                candidates.push_back({x, y});
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && graph[nx][ny] <= size) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        if (candidates.empty()) ret += 1;
        else break;
    }
    if (candidates.empty()) {
        return {-1, {-1, -1}};
    } else {
        //물고기를 먹음
        pii res = *min_element(candidates.begin(), candidates.end());
        graph[res.first][res.second] = 0;
        return {ret, {res.first, res.second}};
    }
}

int go(int x, int y) {
    int ret = 0, size = 2, cnt = 0; //cnt -> 현재 사이즈에서 잡아먹은 물고기
    while (fishes != 0) {
        int time;
        pii pair;
        tie(time, pair) = bfs(x, y, size);
        tie(x, y) = pair;
//        cout << x << ' ' << y << ' ' << time << '\n';
        if (time == -1) {
            break;
        }
        cnt += 1;
        ret += time;
        fishes -= 1;
        memset(visited, 0 , sizeof(visited));
        if (size == cnt) {
            size += 1;
            cnt = 0;
        }
    }
    return ret;
}

int main() {
    FastIO
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 9) {
                x = i;
                y = j;
                graph[i][j] = 0;
            } else if (graph[i][j] != 0) {
                fishes += 1;
            }
        }
    }
    cout << go(x, y);
    return 0;
}