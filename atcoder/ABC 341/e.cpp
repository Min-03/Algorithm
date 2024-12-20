#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDiff[500'001];
int sums[500'001];

int main() {
    FastIO
    int n, q;
    string s;
    cin >> n >> q >> s;
    isDiff[0] = true;
    for (int i = 1; i < n; i++) {
        isDiff[i] = s[i - 1] != s[i];
    }
    for (int i = 1; i <= n; i++) sums[i] = sums[i - 1] + isDiff[i - 1];
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            //isDiff : i번째 -> isDiff[i - 1]
            //sums : i번째 -> sums[i]
            isDiff[l - 1] = !isDiff[l - 1]; //l번째
            isDiff[r] = !isDiff[r]; //r + 1번째
        } else {
            cout << (sums[r] - sums[l - 1] == r - l + 1 ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}