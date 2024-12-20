#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int heights[10];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < n; j++) {
            if (heights[j]) continue;
            if (cnt == 0) {
                heights[j] = i;
                break;
            }
            cnt--;
        }
    }
    for (int i = 0; i < n; i++) cout << heights[i] << ' ';
    return 0;
}