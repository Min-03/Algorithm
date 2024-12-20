#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dists[1001][1001];

int main() {
    FastIO
    int n, m, x;
    cin >> n >> m >> x;

    memset(dists, inf, sizeof(dists));
    for (int i = 1; i <= n; i++) {
        dists[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        dists[s][e] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dists[i][x] + dists[x][i]);
    }
    cout << ans;
    return 0;
}