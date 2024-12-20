#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

int dists[10'001];
vector<pair<int,int>> graph[10'001];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dists[s] = 0;
    pq.push({dists[s], s});
    while(!pq.empty()) {
        auto [dist, curr] = pq.top(); pq.pop();
        if (dists[curr] < dist) continue;
        for (auto [w, next] : graph[curr]) {
            if (dists[next] <= dist + w) continue;
            dists[next] = dist + w;
            pq.push({dists[next], next});
        }
    }

}

int main() {
    FASTIO
    int tc;
    cin >> tc;
    while (tc--) {
        int n, d, c;
        cin >> n >> d >> c;
        memset(dists, inf, sizeof(dists));
        for (int i = 1; i <= n; i++) graph[i].clear();

        for (int i = 0; i < d; i++) {
            int e, s, w;
            cin >> e >> s >> w;
            graph[s].push_back({w, e});
        }
        dijkstra(c);
        int hi = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (dists[i] != inf) {
                hi = max(hi, dists[i]);
                cnt++;
            }
        }
        cout << cnt << ' ' << hi << '\n';
    }
    return 0;
}