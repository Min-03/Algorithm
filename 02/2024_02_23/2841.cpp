#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

stack<int> s[7];

int main() {
    FastIO
    int n, p, ans = 0;
    cin >> n >> p;
    while (n--) {
        int num, plat;
        cin >> num >> plat;
        while (!s[num].empty() && s[num].top() > plat) {
            s[num].pop();
            ans++;
        }
        if (!s[num].empty() && s[num].top() == plat) continue;
        s[num].push(plat);
        ans++;
    }
    cout << ans;
    return 0;
}