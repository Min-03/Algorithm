#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct cmp {
    bool operator ()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> cnts(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cnts[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 1; i <= n; i++) {
        pq.push({cnts[i], i});
    }
    int ans = 0;
    while (true) {
        auto [curr, idx] = pq.top(); pq.pop();
        if (idx == 1) break;
        pq.push({curr - 1, idx});
        pq.push({++cnts[1], 1});
        ans++;
    }
    cout << ans;
    return 0;
}