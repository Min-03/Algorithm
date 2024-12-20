#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int pos[1000];

int main() {
    FastIO
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos, pos + n);
    int before = pos[0];
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (pos[i] - before + 1 > l) {
            before = pos[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}