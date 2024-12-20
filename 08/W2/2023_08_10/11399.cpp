#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int times[1000];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    sort(times, times + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += times[i] * (n - i);
    }
    cout << ans;
    return 0;
}