#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[101];
bool virus[101];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    virus[1] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            if (!virus[ngb]) {
                virus[ngb] = true;
                q.push(ngb);
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (virus[i]) ans++;
    }
    cout << ans;
    return 0;
}