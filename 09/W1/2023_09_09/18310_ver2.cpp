#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int pos[200'001];
long long sums[200'001];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    sort(pos + 1, pos + n + 1);

    long long sum = 0;
    sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum += pos[i];
        sums[i] = sum;
    }

    long long lo = 1e12, ans = -1;
    for (int i = 1; i <= n; i++) {
        //i번째 집에 안테나 설치
        long long dist = (long long) (i - 1) * pos[i] - (sums[i - 1] - sums[0]);
        dist += sums[n] - sums[i] - (long long) (n - i) * pos[i];
        if (lo > dist) {
            lo = dist;
            ans = i;
        }
    }
    cout << pos[ans];
    return 0;
}