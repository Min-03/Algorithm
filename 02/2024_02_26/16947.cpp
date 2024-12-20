#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

vector<int> graph[3001];
int type[3001], parent[3001];
int dists[3001];

void updateCycle(int curr, int st) {
    dists[curr] = 0;
    if (curr == st) return;
    updateCycle(parent[curr], st);
}

void dfs(int x, int p) {
    type[x] = 1;
    for (int ngb : graph[x]) {
        if (type[ngb] == 1 && p != ngb) {
            updateCycle(x, ngb);
        } else if (type[ngb] == 0) {
            parent[ngb] = x;
            dfs(ngb, x);
        }
    }
    type[x] = 2;
}

void bfs(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (dists[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            if (dists[ngb] == inf) {
                dists[ngb] = dists[curr] + 1;
                q.push(ngb);
            }
        }
    }
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(dists, inf, sizeof(dists));
    dfs(1, -1);
    bfs(n);
    for (int i = 1; i <= n; i++) {
        cout << dists[i] << ' ';
    }
    return 0;
}