#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int graph[11][11];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int ans = 0;
    vector<int> visits(n);
    for (int i = 0; i < n; i++) {
        visits[i] = i + 1;
    }
    do {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (graph[visits[i]][visits[i + 1]] == 0) {
                res = max(res, cnt);
                cnt = 0;
            }
            cnt += graph[visits[i]][visits[i + 1]];
        }
        res = max(res, cnt);
        ans = max(ans, res);
    } while (next_permutation(visits.begin(), visits.end()));
    cout << ans;
    return 0;
}