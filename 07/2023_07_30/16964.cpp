#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100'001];
int prior[100'001];
bool visited[100'001];
int input[100'001];
int indexIn = 0;

bool compare(int x, int y) {
    return prior[x] < prior[y];
}

bool dfs(int curr) {
    visited[curr] = true;
    if (input[indexIn++] != curr) return false;
    for (int ngb : graph[curr]) {
        if (!visited[ngb] && !dfs(ngb)) return false;
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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        prior[input[i]] = cnt++;
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }
    if (input[0] != 1) {
        cout << 0;
        return 0;
    }
    cout << (dfs(1) ? 1 : 0);
    return 0;
}