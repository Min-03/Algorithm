#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int aPos = 0, bPos = 0;
    while (aPos < n && bPos < m) {
        if (a[aPos] <= b[bPos]) {
            cout << a[aPos++] << ' ';
        } else {
            cout << b[bPos++] << ' ';
        }
    }
    while (aPos < n) {
        cout << a[aPos++] << ' ';
    }
    while (bPos < m) {
        cout << b[bPos++] << ' ';
    }
    return 0;
}