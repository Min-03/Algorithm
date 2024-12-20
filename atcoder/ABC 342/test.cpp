#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDivided[200'001];
vector<int> primes;

int main() {
    FastIO
    isDivided[0] = true;
    isDivided[1] = true;
    for (int i = 2; i * i <= 200'000; i++) {
        if (isDivided[i]) continue;
        for (int j = 2 * i; j <= 200'000; j += i) {
            isDivided[j] = true;
        }
    }
    for (int i = 0; i <= 200'000; i++) {
        if (!isDivided[i]) primes.push_back(i);
    }
    int tot = 1;
    for (int prime : primes) {
        cout << prime << endl;
        tot *= prime;
        if (tot >= 200'000) {
            cout << prime;
            return 0;
        }
    }
    return 0;
}