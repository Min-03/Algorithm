#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long power(long long a, int b) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main() {
    FastIO
    int n;
    string password;
    cin >> n >> password;
    long long ans = 0;
    for (int i = 0; i < password.length(); i++) {
        char ch = password[i];
        ans += (ch - 'a') * (power(26, n - i) - 1) / 25;
        ans++;
    }
    cout << ans;
    return 0;
}