#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> times;
int n, m;

bool check(long long x) {
    long long cnt = 0;
    for (int time : times) {
        cnt += x / time + 1;
    }
    return cnt >= n;
}

int main() {
    FastIO
    cin >> n >> m;

    times.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> times[i];
    }

    long long lo = -1, hi = (long long) n * 30 / m;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }

    long long left = n;
    for (int i = 0; i < m; i++) {
        left -= hi / times[i] + 1;
        if (hi % times[i] == 0) left++;
    }

    for (int i = 0; i < m; i++) {
        if (hi % times[i] == 0) left--;
        if (left == 0) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}