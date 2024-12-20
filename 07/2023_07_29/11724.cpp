#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[1001];
bool visited[1001];
void dfs(int curr) {
    visited[curr] = true;
    for (int ngb : graph[curr]) {
        if (!visited[ngb]) {
            dfs(ngb);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}