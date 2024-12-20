#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100'001];
int parent[100'001];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (int ngb : graph[x]) {
            if (parent[ngb] == 0) {
                q.push(ngb);
                parent[ngb] = x;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}
