#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> liters(n);
    for (int i = 0; i < n; i++) {
        cin >> liters[i];
    }
    sort(liters.begin(), liters.end(), greater<int>());
    double ans = liters[0];
    for (int i = 1; i < n; i++) {
        ans += (double) liters[i] / 2;
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}