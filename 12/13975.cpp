#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

int main() {
    FASTIO
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 0; i < n; i++) {
            ll cost;
            cin >> cost;
            pq.push(cost);
        }

        ll tot = 0;
        while (pq.size() > 1) {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            tot += a + b;
            pq.push(a + b);
        }
        cout << tot << '\n';
    }
    return 0;
}