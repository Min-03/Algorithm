#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        cout << binary_search(a.begin(), a.end(), num) << ' ';
    }

    return 0;
}