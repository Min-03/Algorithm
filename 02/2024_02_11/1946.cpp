#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> vec;

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        vec.clear();
        int n;
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            vec[i] = {a, b};
        }
        sort(vec.begin(), vec.end());
        int lo = 1e6, cnt = 0;
        for (auto [_, score] : vec) {
            if (score > lo) continue;
            cnt++;
            lo = min(lo, score);
        }
        cout << cnt << '\n';
    }
    return 0;
}