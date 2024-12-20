#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i  = 0; i < n; i++) {
        int num;
        cin >> num;
        a[i] = {num, i};
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = a[i].second;
        ans = max(ans, pos - i);
    }
    cout << ans + 1;
    return 0;
}