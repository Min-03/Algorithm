#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main() {
    FastIO
    int h, w, ans = 0, hi = 0, hiIdx = 0;
    cin >> h >> w;
    vector<int> heights(w);
    for (int i = 0; i < w; i++) {
        cin >> heights[i];
        int nxt = min(hi, heights[i]);
        for (int j = hiIdx; j < i; j++) {
            if (heights[j] < nxt) {
                ans += nxt - heights[j];
                heights[j] = nxt;
            }
        }
        if (heights[i] > hi) {
            hi = heights[i];
            hiIdx = i;
        }
    }
    cout << ans;
    return 0;
}