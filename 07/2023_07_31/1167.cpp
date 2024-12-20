#include <bits/stdc++.h>
using namespace std;

struct Node {
    int num;
    int distance;
};
vector<pair<int, int>> graph[100'001];
int dist[100'001];

Node bfs(int node) {
    memset(dist, -1, sizeof(dist));
    dist[node] = 0;
    queue<int> q;
    q.push(node);
    Node res = {0, 0}; //노드, 거리
    while (!q.empty()) {
        node = q.front(); q.pop();
        for (pair<int, int> ngb : graph[node]) {
            int next, weight;
            tie(next, weight) = ngb;
            if (dist[next] == -1) {
                dist[next] = dist[node] + weight;
                q.push(next);
                if (dist[next] > res.distance) {
                    res.distance = dist[next];
                    res.num = next;
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v;
    cin >> v;
    for (int i = 0; i < v; i++) {
        int a, b, w;
        cin >> a >> b;
        while (b != -1) {
            cin >> w;
            graph[b].emplace_back(a, w);
            graph[a].emplace_back(b, w);
            cin >> b;
        }
    }
    int u = bfs(1).num;
    cout << bfs(u).distance;
    return 0;
}
