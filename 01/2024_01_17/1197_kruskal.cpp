#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct Edge {
    int u, v, w;
    bool operator <(Edge const& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
int parent[10'001];
int ranks[10'001];

int find_set(int x) {
    if (parent[x] != x) return parent[x] = find_set(parent[x]);
    else return x;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (ranks[a] > ranks[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
        if (ranks[a] == ranks[b]) ranks[b]++;
    }
}

int kruskal() {
    int ret = 0;
    sort(edges.begin(), edges.end());
    for (auto [u, v, w] : edges) {
        if (find_set(u) != find_set(v)) {
            union_set(u, v);
            ret += w;
        }
    }
    return ret;
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    iota(parent + 1, parent + n + 1, 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge = {u, v, w};
        edges.push_back(edge);
    }
    cout << kruskal();
    return 0;
}