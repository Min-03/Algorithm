#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    long long sum = 0, lo = 1e15;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        sum += num;
        lo = min(lo, sum);
    }
    long long add = (lo < 0 ? abs(lo) : 0);
    cout << sum + add;
    return 0;
}