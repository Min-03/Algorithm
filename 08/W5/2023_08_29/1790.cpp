#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int getLength(int x) {
    int length = 0;
    int end, start = 1, level = 1;
    while (start <= x) {
        end = min(x, start * 10 - 1);
        length += level * (end - start + 1);
        start *= 10;
        level++;
    }
    return length;
}

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    if (getLength(n) < k) {
        cout << -1;
        return 0;
    }
    int lo = -1, hi = 1e8 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (getLength(mid) < k) lo = mid;
        else hi = mid;
    }
    k -= getLength(lo);
    string last = to_string(lo + 1);
    for (char ch : last) {
        k--;
        if (k == 0) {
            cout << ch - '0';
            break;
        }
    }
    return 0;
}