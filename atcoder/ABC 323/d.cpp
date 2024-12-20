#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long s, c, lev = 1;
        cin >> s >> c;
        while (c > 0) {
            if (c & 1) pq.push(s * (1 << (lev - 1)));
            c /= 2;
            lev++;
        }
    }

    int ans = 0;
    while (!pq.empty()) {
        long long curr = pq.top(); pq.pop();
        if (!pq.empty() && curr == pq.top()) {
            pq.pop();
            pq.push(2 * curr);
        } else {
            ans++;
        }
    }
    cout << ans;
    return 0;
}