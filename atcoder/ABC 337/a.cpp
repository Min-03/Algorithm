#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int aSum = 0, bSum = 0;
    for (int i = 0; i < n; i++) {
        aSum += a[i];
        bSum += b[i];
    }
    if (aSum > bSum) cout << "Takahashi";
    else if (aSum < bSum) cout << "Aoki";
    else cout << "Draw";
    return 0;
}