#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ans += num;
        pq.push(num);
    }
    for (int i = 0; i < m; i++) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
        pq.push(a + b);
    }
    cout << ans;
    return 0;
}