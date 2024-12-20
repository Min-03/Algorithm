#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int big[100], small[100];
vector<int> graph[100];
bool visited[100];

int bfs(int start) {
    visited[start] = true;
    int ret = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        ret++;
        big[curr]++;
        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return ret - 1;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        small[i] = bfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (big[i] - 1 > n / 2 || small[i] > n / 2) ans++;
    }
    cout << ans;
    return 0;
}