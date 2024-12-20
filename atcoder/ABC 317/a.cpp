#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, h, x;
    cin >> n >> h >> x;
    vector<int> potions(n);
    for (int i = 0; i < n; i++) {
        cin >> potions[i];
    }
    for (int i = 0; i < n; i++) {
        if (h + potions[i] >= x) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}