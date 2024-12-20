#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> lengths;
int n, m;

bool check(long long num) {
    int cnt = 1;
    long long curr = -1;
    for (int length : lengths) {
        if (curr + length + 1 <= num) curr += length + 1;
        else {
            curr = length;
            cnt++;
        }
    }
    return cnt <= m;
}

int main() {
    FastIO
    cin >> n >> m;
    lengths.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    long long lo = *max_element(lengths.begin(), lengths.end()) - 1, hi = accumulate(lengths.begin(), lengths.end(), 0LL) + n;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}