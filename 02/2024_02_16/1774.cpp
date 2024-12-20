#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int parents[1'001], ranks[1'001];
vector<tuple<double, int, int>> edges;
vector<pair<ll, ll>> points;

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (ranks[a] > ranks[b]) swap(a, b);
    parents[a] = b;
    ranks[b] += ranks[a] == ranks[b];
}

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    for (int i = 0; i < n; i++) {
        auto [x1, y1] = points[i];
        for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = points[j];
            double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            edges.push_back({dist, i, j});
        }
    }
    for (int i = 0; i < n; i++) parents[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_set(--a, --b);
    }
    double ans = 0;
    sort(edges.begin(), edges.end());
    for (auto [dist, a, b] : edges) {
        if (find_set(a) != find_set(b)) {
            ans += dist;
            union_set(a, b);
        }
    }
    printf("%.2lf", ans);
    return 0;
}