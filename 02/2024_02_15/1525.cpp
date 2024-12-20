#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<string, int> dist;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

string swapNum(int x1, int y1, int x2, int y2, const string& str) {
    string ret = str;
    int idx1 = 3 * x1 + y1;
    int idx2 = 3 * x2 + y2;
    swap(ret[idx1], ret[idx2]);
    return ret;
}

int bfs(const string& s, int sx, int sy) {
    queue<tuple<string, int, int>> q;
    q.push({s, sx, sy});
    dist[s] = 0;
    while (!q.empty()) {
        auto [set, x, y] = q.front(); q.pop();
        if (set == "123456780") return dist[set];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            string nxtSet = swapNum(x, y, nx, ny, set);
            if (dist.find(nxtSet) != dist.end()) continue;
            dist[nxtSet] = dist[set] + 1;
            q.push({nxtSet, nx, ny});
        }
    }
    return -1;
}

int main() {
    FastIO
    int input = 0, sx, sy;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            cin >> num;
            input = 10 * input + num;
            if (num == 0) {
                sx = i;
                sy = j;
            }
        }
    }
    cout << bfs(to_string(input), sx, sy);
    return 0;
}