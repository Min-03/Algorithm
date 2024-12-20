#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> pos;
vector<int> lens;

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    pos.resize(n);
    for (int &i : pos) cin >> i;
    sort(pos.begin(), pos.end());
    for (int i = 1; i < n; i++) lens.push_back(pos[i] - pos[i - 1]);
    sort(lens.begin(), lens.end(), greater<>());
    int ans = 0;
    for (int len : lens) {
        if (k > 1) {
            k--;
        } else {
            ans += len;
        }
    }
    cout << ans;
    return 0;
}