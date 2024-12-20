#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> edges;
vector<int> lis;
int parent[500'001];
bool used[500'001];

int main() {
    FastIO
    int n;
    cin >> n;
    edges.reserve(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    sort(edges.begin(), edges.end());
    for (auto [a, b] : edges) {
        auto it = lower_bound(lis.begin(), lis.end(), b);
        if (it != lis.begin()) parent[b] = *(it - 1);
        if (it == lis.end()) {
            lis.push_back(b);
        } else {
            *it = b;
        }
    }
    cout << n - lis.size() << '\n';
    int curr = lis.back();
    while (curr != 0) {
        used[curr] = true;
        curr = parent[curr];
    }
    for (auto [a, b] : edges) {
        if (!used[b]) cout << a << '\n';
    }
    return 0;
}