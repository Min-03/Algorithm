#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n + 1; i++) {
        if (i & 1) cout << '0';
        else cout << '1';
    }
    return 0;
}