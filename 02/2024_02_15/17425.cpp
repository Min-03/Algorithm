#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long sums[1'000'001];

int main() {
    FastIO
    int tc;
    cin >> tc;
    for (int i = 1; i <= 1'000'000; i++) {
        for (int j = i; j <= 1'000'000; j += i) {
            sums[j] += i;
        }
    }
    for (int i = 1; i <= 1'000'000; i++) sums[i] += sums[i - 1];
    while (tc--) {
        int n;
        cin >> n;
        cout << sums[n] << '\n';
    }
    return 0;
}