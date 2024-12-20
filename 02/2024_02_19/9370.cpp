#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[2001];
int dists[2001][2001];

void init(int n) {
    memset(dists, inf, sizeof(dists));
    for (int i = 0; i <= n; i++) {
        graph[i].clear();
        dists[i][i] = 0;
    }
}

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    dists[s][s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[s][curr] != w) continue;
        for (auto [nw, nxt] : graph[curr]) {
            if (dists[s][curr] + nw < dists[s][nxt]) {
                dists[s][nxt] = dists[s][curr] + nw;
                pq.push({dists[s][nxt], nxt});
            }
        }
    }
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, t, s, g, h, add = 0;
        cin >> n >> m >> t >> s >> g >> h;
        init(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
            if (u == g && v == h || u == h && v == g) add = w;
        }
        vector<int> dests(t);
        for (int &i : dests) cin >> i;
        sort(dests.begin(), dests.end());
        dijkstra(s);
        dijkstra(g);
        dijkstra(h);
        for (int dest : dests) {
            int base = dists[s][dest];
            if (base == dists[s][g] + add + dists[h][dest] || base == dists[s][h] + add + dists[g][dest]) {
                cout << dest << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}