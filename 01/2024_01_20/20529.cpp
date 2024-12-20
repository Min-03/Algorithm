#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int getDist(string a, string b) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) ret++;
    }
    return ret;
}

int main() {
    FastIO

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> vec(n);
        for (string& str : vec) {
            cin >> str;
        }
        if (n > 32) {
            cout << 0 << '\n';
            continue;
        }
        int res = 100;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec.size(); j++) {
                for (int k = 0; k < vec.size(); k++) {
                    if (i == j || j == k || i == k) continue;
                    int dist = getDist(vec[i], vec[j]) + getDist(vec[j], vec[k]) + getDist(vec[i], vec[k]);
                    res = min(res, dist);
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}