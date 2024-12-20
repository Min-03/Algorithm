#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll inf = 5 * 1e18;

struct edge {
    ll l, d, k, c, st;
};

ll times[200'001];
vector<edge> graph[200'001];

void dijkstra(int e) {
    priority_queue<pll> pq; //제일 큰 것 우선
    times[e] = inf;
    pq.push({times[e], e});
    while (!pq.empty()) {
        auto [time, curr] = pq.top(); pq.pop();
        if (times[curr] != time) continue;
        for (auto [l, d, k, c, st] : graph[curr]) {
            if (times[curr] - c >= l) {
                ll coef = min(k - 1, (times[curr] - c - l) / d);
                ll nxtTime = l + coef * d;
                if (nxtTime <= times[st]) continue;
                times[st] = nxtTime;
                pq.push({times[st], st});
            }
        }
    }
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll l, d, k, c, a, b;
        cin >> l >> d >> k >> c >> a >> b;
        graph[b].push_back({l, d, k, c, a});
    }
    for (int i = 1; i <= n; i++) times[i] = -inf;
    dijkstra(n);
    for (int i = 1; i < n; i++) {
        if (times[i] == -inf) cout << "Unreachable\n";
        else cout << times[i] << '\n';
    }
    return 0;
}