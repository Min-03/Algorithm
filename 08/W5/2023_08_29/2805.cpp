#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> lengths;
int n, m;

bool check(int x) {
    long long res = 0;
    for (int length : lengths) {
        if (length <= x) continue;
        res += length - x;
    }
    return res >= m;
}

int main() {
    FastIO
    cin >> n >> m;
    lengths.resize(n);
    int hi = -1;
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
        hi = max(hi, lengths[i]);
    }
    int lo = 0;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    return 0;
}