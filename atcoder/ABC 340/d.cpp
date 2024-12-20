#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf = 1e15;

vector<pll> graph[200'001];
ll dists[200'001];
int n;

ll dijkstra() {
    priority_queue<pll, vector<pll>, greater<>> pq;
    dists[1] = 0;
    pq.push({dists[1], 1});
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dists[curr] != w) continue;
        if (curr == n) return dists[curr];
        for (auto [nw, nxt] : graph[curr]) {
            if (dists[curr] + nw < dists[nxt]) {
                dists[nxt] = dists[curr] + nw;
                pq.push({dists[nxt], nxt});
            }
        }
    }
    return -1;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        graph[i].push_back({a, i + 1});
        graph[i].push_back({b, x});
    }
    for (int i = 1; i <= n; i++) dists[i] = inf;
    cout << dijkstra();
    return 0;
}