#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;

int nums[300'000];

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii>> roadA, roadB;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        roadA.push({nums[i], i});
    }
    for (int i = n + 1; i <= n + m; i++) {
        cin >> nums[i];
        roadB.push({nums[i], i});
    }
    int k;
    cin >> k;
    while (k--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'U') {
            int x, y;
            cin >> x >> y;
            nums[x] = y;
            if (x <= n) roadA.push({y, x});
            else roadB.push({y, x});
        } else {
            int a, b;
            while (nums[roadA.top().second] != roadA.top().first) {
                roadA.pop();
            }
            a = roadA.top().second;
            while (nums[roadB.top().second] != roadB.top().first) {
                roadB.pop();
            }
            b = roadB.top().second;
            cout << a << ' ' << b << '\n';
        }
    }
    return 0;
}