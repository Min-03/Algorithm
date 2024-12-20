#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[20'001];
int dists[20'001];

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
    memset(dists, -1, sizeof(dists));
    queue<int> q;
    q.push(1);
    dists[1] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int ngb : graph[curr]) {
            if (dists[ngb] == -1) {
                dists[ngb] = dists[curr] + 1;
                q.push(ngb);
            }
        }
    }
    int hi = 0;
    for (int i = 1; i <= n; i++) {
        hi = max(hi, dists[i]);
    }
    int num = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dists[i] == hi) {
            if (cnt == 0) num = i;
            cnt++;
        }
    }
    cout << num << ' ' << hi << ' ' << cnt;
    return 0;
}