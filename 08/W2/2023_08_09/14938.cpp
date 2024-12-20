#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 1e9;

vector<pii> graph[101];
int dist[101];
int items[101];
int n;

void dijkstra(int node) {
    fill(dist + 1, dist + n + 1, inf);
    dist[node] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, node});
    while (!pq.empty()) {
        auto [cost, curr] = pq.top(); pq.pop();
        if (dist[curr] < cost) continue;
        for (auto [next, nextW] : graph[curr]) {
            if (dist[next] > dist[curr] + nextW) {
                dist[next] = dist[curr] + nextW;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    FastIO
    int m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int curr = 0;
        dijkstra(i);
        for (int j = 1; j <= n; j++) {
            if (dist[j] <= m) {
                curr += items[j];
            }
        }
        ans = max(ans, curr);
    }
    cout << ans;
    return 0;
}