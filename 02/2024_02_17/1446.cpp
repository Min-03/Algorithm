#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[10'001];
int dists[10'001];

int dijkstra(int s, int e) {
    dists[s] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[curr] != w) continue;
        for (auto [nw, nxt] : graph[curr]) {
            if (dists[curr] + nw < dists[nxt]) {
                dists[nxt] = dists[curr] + nw;
                pq.push({dists[nxt], nxt});
            }
        }
    }
    return dists[e];
}

int main() {
    FastIO
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < d; i++) graph[i].push_back({1, i + 1});
    memset(dists, inf, sizeof(dists));
    for (int i = 0; i < n; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({w, e});
    }
    cout << dijkstra(0, d);
    return 0;
}