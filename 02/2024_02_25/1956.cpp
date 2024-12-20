#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dists[401][401];

int main() {
    FastIO
    int v, e;
    cin >> v >> e;
    memset(dists, inf, sizeof(dists));
    for (int i = 0; i < e; i++) {
        int st, en, w;
        cin >> st >> en >> w;
        dists[st][en] = w;
    }
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
    int lo = inf;
    for (int i = 1; i <= v; i++) lo = min(lo, dists[i][i]);
    cout << (lo == inf ? -1 : lo);
    return 0;
}