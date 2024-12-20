#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[401];
vector<int> back[401];
bool visited[401];
bool contains[401][401];

void dfs(int x) {
    visited[x] = true;
    for (int ngb : graph[x]) {
        if (!visited[ngb]) dfs(ngb);
        contains[x][ngb] = true;
        back[x].push_back(ngb);
        for (int n : back[ngb]) {
            if (contains[x][n]) continue;
            back[x].push_back(n);
            contains[x][n] = true;
        }
    }
}

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int s, e;
        cin >> s >> e;
        if (contains[s][e]) {
            cout << -1 << '\n';
        } else if (contains[e][s]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}