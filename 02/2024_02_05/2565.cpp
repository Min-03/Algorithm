#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> lis;
    vector<pair<int, int>> edges(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
    }
    sort(edges.begin(), edges.end());
    for (auto [a, b] : edges) {
        auto it = lower_bound(lis.begin(), lis.end(), b);
        if (it == lis.end()) lis.push_back(b);
        else *it = b;
    }
    cout << n - lis.size();
    return 0;
}