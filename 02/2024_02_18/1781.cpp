#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;

priority_queue<pii> ramen;
priority_queue<int> vals;

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int dead, val;
        cin >> dead >> val;
        ramen.push({dead, val});
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        while (!ramen.empty() && ramen.top().first >= i) {
            vals.push(ramen.top().second);
            ramen.pop();
        }
        if (!vals.empty()) {
            ans += vals.top(); vals.pop();
        }
    }
    cout << ans;
    return 0;
}