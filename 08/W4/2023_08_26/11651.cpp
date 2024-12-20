#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].second >> pairs[i].first;
    }
    sort(pairs.begin(), pairs.end());
    for (auto [y, x] : pairs) {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}