#include <bits/stdc++.h>
using namespace std;

int cnts[101];
int from[101];

int bfs() {
    queue<int> q;
    cnts[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == 100) {
            return cnts[x];
        }
        for (int i = 1; i <= 6; i++) {
            if (cnts[from[x + i]] == -1) {
                cnts[from[x + i]] = cnts[x] + 1;
                q.push(from[x + i]);
            }
        }
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 100; i++) {
        from[i] = i;
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        int u, v;
        cin >> u >> v;
        from[u] = v;
    }
    memset(cnts, -1, sizeof(cnts));
    cout << bfs();
    return 0;
}