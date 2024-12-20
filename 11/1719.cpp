#include<bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

int dists[201][201];
int prevs[201][201]; //prevs[i][j] : i에서 j로 이동 시 가장 먼저 거쳐야 되는 집하장

int main() {
    FASTIO
    int n, m;
    cin >> n >> m;
    memset(dists, inf, sizeof(dists));
    for (int i = 1; i <= n; i++) dists[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (dists[u][v] > w) {
            dists[u][v] = w;
            prevs[u][v] = v;
        }
        if (dists[v][u] > w) {
            dists[v][u] = w;
            prevs[v][u] = u;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dists[i][j] > dists[i][k] + dists[k][j]) {
                    dists[i][j] = dists[i][k] + dists[k][j];
                    prevs[i][j] = prevs[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << prevs[i][j] << " ";
        }
        cout << '\n';
    }
}