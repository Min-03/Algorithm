#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        while (!s.empty() && s.top().first >= num) {
            int h = s.top().first; s.pop();
            int w = (s.empty() ? i : i - 1 - s.top().second);
            ans = max(ans, h * w);
        }
        s.push({num, i});
    }

    while (!s.empty()) {
        int h = s.top().first; s.pop();
        int w = (s.empty() ? n : n - 1 - s.top().second);
        ans = max(ans, h * w);
    }
    cout << ans;
    return 0;
}