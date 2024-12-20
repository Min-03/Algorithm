#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> predicts(n);
    for (int i = 0; i < n; i++) {
        cin >> predicts[i];
    }
    sort(predicts.begin(), predicts.end());
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(i - predicts[i - 1]);
    }
    cout << ans;
    return 0;
}