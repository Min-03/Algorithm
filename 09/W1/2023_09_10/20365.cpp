#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, r = 0, b = 0;
    cin >> n;
    vector<char> colors(n);
    cin >> colors[0];
    for (int i = 1; i < n; i++) {
        cin >> colors[i];
        if (colors[i] != colors[i - 1]) {
            if (colors[i - 1] == 'B') b++;
            else r++;
        }
    }
    if (colors[n - 1] == 'B') b++;
    else r++;
    cout << min(r + 1, b + 1);
    return 0;
}