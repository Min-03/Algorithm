#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool eaten[20'000];
char arr[20'000];

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'H') continue;
        for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
            if (arr[j] == 'H' && !eaten[j]) {
                ans++;
                eaten[j] = true;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}