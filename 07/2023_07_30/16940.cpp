#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100'001];
int input[100'000];
bool visited[100'001];
unordered_map<int, int> prior;

bool compare(int x, int y) {
    return prior[x] < prior[y];
}

bool bfs(int curr) {
    queue<int> q;
    q.push(curr);
    visited[curr] = true;
    int index = 0;
    while (!q.empty()) {
        curr = q.front(); q.pop();
        if (input[index++] != curr) return false;
        for (int ngb : graph[curr]) {
            if (!visited[ngb]) {
                visited[ngb] = true;
                q.push(ngb);
            }
        }
    }
    return true;
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
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        prior.insert({input[i], cnt++});
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }

    if (input[0] != 1) {
        cout << 0;
        return 0;
    }
    cout << (bfs(1) ? 1 : 0);
    return 0;
}