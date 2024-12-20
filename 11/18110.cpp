#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FASTIO
    int n, sum = 0;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int out = round(0.15 * n);
    sort(v.begin(), v.end());
    for (int i = out; i < n - out; i++) sum += v[i];
    cout << round(sum / (double) (n - 2 * out));
}