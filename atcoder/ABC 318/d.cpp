#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

long long costs[17][17];
bool used[17];
long long ans = 0;
int n;

void go(int currS, long long cost) {
    if (currS == n + 1) {
        ans = max(ans, cost);
        return;
    }
    if (used[currS]) {
        go(currS + 1, cost);
        return;
    }

    for (int i = currS + 1; i <= n; i++) {
        if (used[i]) continue;
        used[currS] = used[i] = true;
        go(currS + 1, cost + costs[currS][i]);
        used[currS] = used[i] = false;
    }
    go(currS + 1, cost);
}

int main() {
    FastIO
    cin >> n;
    for (int s = 1; s <= n; s++) {
        for (int e = s + 1; e <= n; e++) {
            cin >> costs[s][e];
        }
    }
    go(1, 0);
    cout << ans;
    return 0;
}