#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> edges;

int main() {
    FastIO
    int n;
    cin >> n;
    edges.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    sort(edges.begin(), edges.end());
    long long tot = 0, e = -1e10;
    for (auto [x, y] : edges) {
        if (e > y) continue;
        if (e <= x) tot += y - x;
        else tot += y - e;
        e = y;
    }
    cout << tot;
    return 0;
}