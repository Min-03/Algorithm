#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct edge {
    int a, b, w;
    bool operator <(const edge &oth) const {
        return w < oth.w;
    }
};

vector<edge> edges;
int parents[1'001], ranks[1'001];

int find_set(int x) {
    if (x == parents[x]) return x;
    else return  parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    parents[a] = b;
    ranks[b] += ranks[a] == ranks[b];
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    edges.reserve(m);
    for (int i = 1; i <= n; i++) parents[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto [a, b, w] : edges) {
        if (find_set(a) != find_set(b)) {
            union_set(a, b);
            ans += w;
        }
    }
    cout << ans;
    return 0;
}