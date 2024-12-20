#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dists[501][501];

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, w;
        cin >> n >> m >> w;
        memset(dists, inf, sizeof(dists));
        for (int i = 1; i <= n; i++) {
            dists[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v, t;
            cin >> u >> v >> t;
            dists[u][v] = min(dists[u][v], t);
            dists[v][u] = min(dists[v][u], t);
        }

        for (int i = 0; i < w; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            dists[s][e] = min(dists[s][e], -t);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }

        bool found = false;
        for (int i = 1; i <= n; i++) {
            if (dists[i][i] < 0) {
                found = true;
                break;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}