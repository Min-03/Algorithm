#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int parents[200'001];
vector<pair<int, int>> ramen;

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (a < b) swap(a, b);
    parents[a] = b;
}

int main() {
    FastIO
    int n, ans = 0;
    cin >> n;
    ramen.resize(n);
    for (int i = 1; i <= n; i++) parents[i] = i;
    for (int i = 0; i < n; i++) cin >> ramen[i].second >> ramen[i].first;
    sort(ramen.begin(), ramen.end(), greater<>());
    for (auto [val, dead] : ramen) {
        int p = find_set(dead);
        if (p) {
            ans += val;
            union_set(p, p - 1);
        }
    }
    cout << ans;
    return 0;
}