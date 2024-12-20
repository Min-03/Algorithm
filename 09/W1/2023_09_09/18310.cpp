#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int pos[200'001];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    sort(pos, pos + n + 1);
    cout << pos[(n + 1) / 2];
    return 0;
}