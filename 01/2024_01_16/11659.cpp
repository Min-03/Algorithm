#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long sums[100'001];

int main() {
    FastIO
    long long sum = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sum += num;
        sums[i] = sum;
    }
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << sums[j] - sums[i - 1] << '\n';
    }
    return 0;
}