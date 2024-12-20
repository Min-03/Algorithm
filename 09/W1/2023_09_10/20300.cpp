#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<long long> losses(n);
    for (int i = 0; i < n; i++) {
        cin >> losses[i];
    }
    sort(losses.begin(), losses.end());
    long long limit = 0;
    if (n & 1) {
        limit = losses.back();
        losses.pop_back();
        n--;
    }

    for (int i = 0; i < n / 2; i++) {
        limit = max(limit, losses[i] + losses[n - 1 - i]);
    }
    cout << limit;
    return 0;
}