#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

vector<pii> graph[1001], revGraph[1001];
int dists[1001], total[1001];

int main() {
    FastIO
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        revGraph[e].push_back({s, w});
    }
    memset(dists, inf, sizeof(dists));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    dists[x] = 0;
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[curr] < w) continue;
        for (auto [next, nextW] : graph[curr]) {
            if (w + nextW < dists[next]) {
                dists[next] = w + nextW;
                pq.push({dists[next], next});
            }
        }
    }

    //x -> i 비용이 total[i]에 저장
    for (int i = 1; i <= n; i++) {
        total[i] = dists[i];
    }

    memset(dists, inf, sizeof(dists));
    pq = priority_queue<pii, vector<pii>, greater<pii>>();
    pq.push({0, x});
    dists[x] = 0;
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[curr] < w) continue;
        for (auto [next, nextW] : revGraph[curr]) {
            if (w + nextW < dists[next]) {
                dists[next] = w + nextW;
                pq.push({dists[next], next});
            }
        }
    }

    int ans = 0;
    //i -> s 비용이 dists[i]에 저장
    for (int i = 1; i <= n; i++) {
        ans = max(ans, total[i] + dists[i]);
    }
    cout << ans;
    return 0;
}