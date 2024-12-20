#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    string ans;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        int digit = 10;
        for (int j = 9; j >= 1; j--) {
            if (n % j == 0 && i % (n / j) == 0) digit = j;
        }
        if (digit == 10) ans += '-';
        else ans += digit + '0';
    }
    cout << ans;
    return 0;
}