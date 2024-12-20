#include <bits/stdc++.h>
using namespace std;
bool found;
vector<int> graph[2000];
bool visited[2000];
void findPath(int index, int person) {
    if (index == 4) {
        found = true;
        return;
    }
    if (graph[person].empty()) {
        return;
    }
    for (int ngb : graph[person]) {
        if (visited[ngb]) continue;
        visited[ngb] = true;
        findPath(index + 1, ngb);
        visited[ngb] = false;
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int a = 0; a < n; a++) {
        fill(visited, visited + n, 0);
        visited[a] = true;
        findPath(0, a);
        if (found) {
            break;
        }
    }
    cout << (found ? 1 : 0);
    return 0;
}
