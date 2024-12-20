#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[100'001];
int dist[100'001];
bool visited[100'001];

int prim() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    int ret = 0, hi = 0;
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dist[curr] != w) continue;
        visited[curr] = true;
        hi = max(hi, w);
        ret += w;
        for (auto [next, nw] : graph[curr]) {
            if (nw < dist[next] && !visited[next]) {
                dist[next] = nw;
                pq.push({nw, next});
            }
        }
    }
    return ret - hi;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    memset(dist, inf, sizeof(dist));
    cout << prim();
    return 0;
}