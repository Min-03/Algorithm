#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

stack<int> s;

int main() {
    FastIO
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        while (!s.empty() && s.top() <= h) s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
    return 0;
}