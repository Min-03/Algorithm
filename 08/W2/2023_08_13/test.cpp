#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDivided[810];

int main() {
    FastIO
    isDivided[0] = isDivided[1] = true;
    for (int i = 2; i * i <= 809; i++) {
        if (isDivided[i]) continue;
        for (int j = 2 * i; j * j <= 809; j += i) {
            isDivided[j] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 809; i++) {
        if (!isDivided[i]) cnt++;
    }
    cout << cnt;
    return 0;
}