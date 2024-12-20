#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dist[401][401];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    memset(dist, inf, sizeof(dist));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        dist[s][e] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int s;
    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] != inf) {
            cout << -1 << '\n';
        } else if (dist[b][a] != inf) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}