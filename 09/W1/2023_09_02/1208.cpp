#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDivided[4'000'001];

int main() {
    FastIO
    int n;
    cin >> n;
    isDivided[0] = isDivided[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (isDivided[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            isDivided[j] = true;
        }
    }

    vector<int> sums;
    int sum = 0;
    sums.push_back(sum);
    for (int i = 2; i <= n; i++) {
        if (!isDivided[i]) {
            sum += i;
            sums.push_back(sum);
        }
    }

    int lp = 0, rp = 0, cnt = 0;
    while (lp <= rp && rp < sums.size()) {
        int num = sums[rp] - sums[lp];
        if (num > n) {
            lp++;
        } else if (num < n) {
            rp++;
        } else {
            lp++;
            rp++;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}