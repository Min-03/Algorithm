#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[10'001];
bool visited[10'001];

int bfs(int s) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int ret = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        ret++;
        for (int ngb : graph[curr]) {
            if (visited[ngb]) continue;
            visited[ngb] = true;
            q.push(ngb);
        }
    }
    return ret;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> e >> s;
        graph[s].push_back(e);
    }
    int hi = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int res = bfs(i);
        if (res > hi) {
            hi = res;
            ans.clear();
            ans.push_back(i);
        } else if (res == hi) {
            ans.push_back(i);
        }
    }
    for (int i : ans) cout << i << ' ';
    return 0;
}