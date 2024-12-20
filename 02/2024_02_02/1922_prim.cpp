#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<int, int> pii;

vector<pair<int, int>> graph[1'001];
int dist[1'001];
bool visited[1'001];

int prim() {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[1] = 0;
    q.push({dist[1], 1});
    int ret = 0;
    while (!q.empty()) {
        auto [w, curr] = q.top(); q.pop();
        if (dist[curr] != w) continue;
        ret += w;
        visited[curr] = true;
        for (auto [nw, nxt] : graph[curr]) {
            if (dist[nxt] > nw && !visited[nxt]) {
                dist[nxt] = nw;
                q.push({nw, nxt});
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
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }
    memset(dist, inf, sizeof(dist));
    cout << prim();
    return 0;
}