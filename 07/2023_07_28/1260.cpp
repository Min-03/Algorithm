#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
bool visited[1001];
void dfs(int curr) {
    cout << curr << ' ';
    visited[curr] = true;
    for (int ngb : graph[curr]) {
        if (!visited[ngb]) {
            dfs(ngb);
        }
    }
}
void bfs(int curr) {
    visited[curr] = true;
    queue<int> queue;
    queue.push(curr);
    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        cout << now << ' ';
        for (int ngb : graph[now]) {
            if (!visited[ngb]) {
                visited[ngb] = true;
                queue.push(ngb);
            }
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start);
    fill(visited, visited + n + 1, 0);
    cout << '\n';
    bfs(start);
    return 0;
}