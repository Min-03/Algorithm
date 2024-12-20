#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[100'001];
int order[100'001];
int cnt = 1;

void dfs(int x) {
    order[x] = cnt++;
    for (int ngb : graph[x]) {
        if (order[ngb] == 0) {
            dfs(ngb);
        }
    }
}

int main() {
    FastIO
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    dfs(r);
    for (int i = 1; i <= n; i++) {
        cout << order[i] << '\n';
    }
    return 0;
}