#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, l;
    cin >> n >> l;
    int len = l;
    while (len <= 100) {
        int add = (len - 1) * len / 2;
        if (add > n) break;
        if ((n - add) % len == 0) {
            for (int i = 0; i < len; i++) cout << (n - add) / len + i << ' ';
            return 0;
        }
        len++;
    }
    cout << -1;
    return 0;
}