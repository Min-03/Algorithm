#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll money[200'001];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> money[i];
    for (int i = 0; i < n - 1; i++) {
        ll s, t;
        cin >> s >> t;
        ll iterNum = money[i] / s;
        money[i + 1] += iterNum * t;
    }
    cout << money[n - 1];
    return 0;
}