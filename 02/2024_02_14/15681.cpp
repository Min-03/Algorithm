#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[100'001];
int cnts[100'001];
bool visited[100'001];

int dfs(int x) {
    cnts[x] = 1;
    visited[x] = true;
    for (int ngb : graph[x]) {
        if (!visited[ngb]) {
            cnts[x] += dfs(ngb);
        }
    }
    return cnts[x];
}

int main() {
    FastIO
    int n, r, q;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(r);
    while (q--) {
        int u;
        cin >> u;
        cout << cnts[u] << '\n';
    }
    return 0;
}