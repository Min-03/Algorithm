#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool used[1001];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int l = 0; l <= n; l++) {
        for (int v = 0; v + l <= n; v++) {
            for (int x = 0; x + v + l <= n; x++) {
                for (int i = 0; i + x + v + l <= n; i++) {
                    if (i + v + x + l != n) continue;
                    int num = i + 5 * v + 10 * x + 50 * l;
                    used[num] = true;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 1000; i++) {
        if (used[i]) cnt++;
    }
    cout << cnt;
    return 0;
}