#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int tot[5];

int main() {
    FastIO
    vector<pair<int, int>> lens;
    int each;
    cin >> each;
    for (int i = 0; i < 6; i++) {
        int dir, len;
        cin >> dir >> len;
        tot[dir] += len;
        lens.push_back({dir, len});
    }
    int ver = max(tot[3], tot[4]), hor = max(tot[1], tot[2]);
    vector<int> minus;
    for (int i = 0; i < 6; i++) {
        auto [dir, len] = lens[i];
        if (tot[dir] == len) continue;
        auto [pDir, pLen] = lens[(i - 1 + 6) % 6];
        auto [nDir, nLen] = lens[(i + 1) % 6];
        if (tot[nDir] != nLen && tot[pDir] != pLen) {
            minus.push_back(len);
        }
    }
    cout << each * (ver * hor - minus[0] * minus[1]);
    return 0;
}