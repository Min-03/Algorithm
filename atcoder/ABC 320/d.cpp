#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

pair<long long, long long> dists[200'001];
bool visited[200'001];
vector<tuple<int, long long, long long>> graph[200'001]; // (a, x, y) a로부터 x, y만큼 떨어져있음

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long x, y;
        cin >> a >> b >> x >> y;
        graph[a].push_back({b, x, y});
        graph[b].push_back({a, -x, -y});
    }

    queue<int> q;
    q.push(1);
    dists[1] = {0, 0};
    visited[1] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        auto [x, y] = dists[curr];
        for (const auto &[next, nx, ny] : graph[curr]) {
            if (visited[next]) continue;
            visited[next] = true;
            dists[next] = {x + nx, y + ny};
            q.push(next);
        }
    }
    for (int i = 1; i <= n; i++) {
        auto [x, y] = dists[i];
        if (visited[i]) cout << x << ' ' << y << '\n';
        else cout << "undecidable\n";
    }
    return 0;
}