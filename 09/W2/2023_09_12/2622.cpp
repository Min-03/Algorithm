#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = n / 3; i < (n + 1) / 2; i++) {
        for (int j = (n - i) / 2; j <= i; j++) {
            int k = n - i - j;
            if (i >= j && j >= k && k > 0) ans++;
        }
    }
    cout << ans;
    return 0;
}