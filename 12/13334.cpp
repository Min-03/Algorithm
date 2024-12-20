#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> pii;

int main() {
    FASTIO
    int n, d, ans = 0;
    cin >> n;
    vector<pii> lines(n);
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        if (s > e) swap(s, e);
        lines[i] = {e, s};
    }
    cin >> d;
    sort(lines.begin(), lines.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [e, s] : lines) {
        pq.push(s);
        while (!pq.empty() && pq.top() + d < e) pq.pop();
        if (pq.size() > ans) ans = pq.size();
    }
    cout << ans;
}