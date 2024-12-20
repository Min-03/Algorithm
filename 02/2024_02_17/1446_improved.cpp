#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dists[10'001];
vector<pair<int, int>> graph[10'001];

int main() {
    FastIO
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= d; i++) dists[i] = i;
    for (int i = 0; i < n; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({w, e});
    }
    for (int i = 0; i <= d; i++) {
        if (i != 0) dists[i] = min(dists[i - 1] + 1, dists[i]);
        for (auto [w, e] : graph[i]) {
            dists[e] = min(dists[e], dists[i] + w);
        }
    }
    cout << dists[d];
    return 0;
}