#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> rests;
int n, m, l;

bool check(int dist) {
    int last = 0, left = m;
    for (int rest : rests) {
        int diff = rest - last;
        left -= (diff % dist == 0 ? diff / dist - 1 : diff / dist);
        last = rest;
    }
    int diff = l - last;
    left -= (diff % dist == 0 ? diff / dist - 1 : diff / dist);
    return left >= 0;
}

int main() {
    FastIO
    cin >> n >> m >> l;
    rests.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> rests[i];
    }
    sort(rests.begin(), rests.end());
    int lo = 0, hi = l;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}