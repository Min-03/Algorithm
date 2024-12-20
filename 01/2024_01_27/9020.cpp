#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isPrime[10'001];

int main() {
    FastIO
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= 10'000; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j <= 10'000; j += i) {
            isPrime[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        for (int i = num / 2; i > 0; i--) {
            if (isPrime[i] && isPrime[num - i]) {
                cout << i << ' ' << num - i << '\n';
                break;
            }
        }
    }
    return 0;
}