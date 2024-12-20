#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dists[101][101];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    memset(dists, inf, sizeof(dists));
    for (int i = 1; i <= n; i++) {
        dists[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        dists[s][e] = min(dists[s][e], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (dists[i][j] == inf ? 0 : dists[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}