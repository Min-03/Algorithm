#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int inf = 1e9;
vector<pair<int, int>> graph[100'001]; //가중치, 다음 정점
int weight[100'001];

int dijkstra(int start, int end) {
    priority_queue<pair<int, int>> pq;
    pq.push({inf, start});
    weight[start] = inf;
    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (weight[curr] > w) continue;
        for (auto [nextW, next] : graph[curr]) {
            if (weight[next] < min(w, nextW)) {
                weight[next] = min(w, nextW);
                pq.push({weight[next], next});
            }
        }
    }
    return weight[end];
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    int start, end;
    cin >> start >> end;
    cout << dijkstra(start, end);
    return 0;
}