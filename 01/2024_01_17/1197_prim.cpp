#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[10'001];
int dist[10'001];
bool visited[10'001];

int prim() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ret = 0;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        ret += dist[curr];
        for (auto [next, nw] : graph[curr]) {
            if (!visited[next] && dist[next] > nw) {
                dist[next] = nw;
                pq.push({nw, next});
            }
        }
    }
    return ret;
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