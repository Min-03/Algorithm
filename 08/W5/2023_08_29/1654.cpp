#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> lengths;
int n, k;

bool check(long long x) {
    long long cnt = 0;
    for (int length : lengths) {
        int curr = length;
        while (curr >= x) {
            cnt++;
            curr -= x;
        }
    }
    return cnt >= n;
}

int main() {
    FastIO
    cin >> k >> n;
    lengths.resize(k);
    long long lengthSum = 0;
    for (int i = 0; i < k; i++) {
        cin >> lengths[i];
        lengthSum += lengths[i];
    }
    long long lo = 0, hi = lengthSum + 1;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo;
    return 0;
}