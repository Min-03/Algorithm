#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> costs;
int n, m;

bool check(int x) {
    int used = 0;
    for (int cost : costs) {
        used += min(cost, x);
    }
    return used <= m;
}

int main() {
    FastIO
    cin >> n;
    costs.resize(n);
    int hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
        hi = max(hi, costs[i]);
    }
    hi++;
    cin >> m;
    int lo = 0;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}