#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int pos[200'000];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos, pos + n);
    int ans = -1;
    long long lo = 1e9;
    for (int i = pos[0]; i < pos[n - 1]; i++) {
        long long dist = 0;
        for (int j = 0; j < n; j++) {
            dist += abs(i - pos[j]);
        }
        if (dist < lo) {
            ans = i;
            lo = dist;
        }
    }
    cout << ans;
    return 0;
}