#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dist[501][501];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    memset(dist, inf, sizeof(dist));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        dist[s][e] = min(dist[s][e], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == inf || dist[k][j] == inf) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[1][i] != inf && dist[i][i] < 0) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << (dist[1][i] >= inf ? -1 : dist[1][i]) << '\n';
    }
    return 0;
}