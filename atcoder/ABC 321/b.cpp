#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, x;
    cin >> n >> x;
    vector<int> scores(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());
    long long sum = accumulate(scores.begin() + 1, scores.end() - 1, 0LL);
    int lo = scores.front(), hi = scores.back();
    long long needed = x - sum;
    if (needed <= lo) {
        cout << 0;
    } else if (needed <= hi) {
        cout << needed;
    } else {
        cout << -1;
    }
    return 0;
}