#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<tuple<int, bool, int>> buildings; //변화 좌표, 끝점 여부, 높이

int main() {
    FastIO
    int n;
    cin >> n;
    buildings.resize(2 * n);
    for (int i = 0; i < n; i++) {
        int l, h, r;
        cin >> l >> h >> r;
        buildings[2 * i] = {l, false, -h};
        buildings[2 * i + 1] = {r, true, -h};
    }
    sort(buildings.begin(), buildings.end());
    priority_queue<int> pq, del;
    int before = -1;
    vector<pair<int, int>> ans;
    ans.reserve(2 * n);
    for (auto [point, isEnd, h] : buildings) {
        h = -h;
        if (isEnd) {
            del.push(h);
        } else {
            pq.push(h);
        }
        while (!del.empty() && del.top() == pq.top()) {
            del.pop();
            pq.pop();
        }
        int now = pq.empty() ? 0 : pq.top();
        if (before != now) {
            ans.push_back({point, now});
        }
        before = now;
    }

    for (int i = 0; i < ans.size() - 1; i++) {
        if (ans[i].first == ans[i + 1].first) continue;
        cout << ans[i].first << ' ' << ans[i].second << ' ';
    }
    cout << ans.back().first << ' ' << ans.back().second;
    return 0;
}