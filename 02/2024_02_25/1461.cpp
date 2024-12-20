#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < 0) neg.push_back(num);
        else pos.push_back(num);
    }
    //절댓값이 큰 부분이 먼저 오도록 정렬
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<>());
    for (int i = 0; i < pos.size(); i += m) ans += 2 * pos[i];
    for (int i = 0; i < neg.size(); i += m) ans += 2 * abs(neg[i]);
    if (neg.empty() || !pos.empty() && abs(pos[0]) > abs(neg[0])) ans -= pos[0];
    else ans -= abs(neg[0]);
    cout << ans;
    return 0;
}