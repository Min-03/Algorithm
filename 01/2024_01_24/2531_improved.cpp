#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int eaten[3'001];

int main() {
    FastIO
    int n, d, k, c, cnt = 0, ans = 1;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int &i : sushi) cin >> i;
    for (int i = 0; i < k; i++) {
        if (sushi[i] != c && eaten[sushi[i]]++ == 0) cnt++;
    }
    ans = max(cnt, ans);
    for (int st = 1; st < n; st++) {
        int en = (st + k - 1) % n;
        if (--eaten[sushi[st - 1]] == 0 && sushi[st - 1] != c) cnt--;
        if (eaten[sushi[en]]++ == 0 && sushi[en] != c) cnt++;
        ans = max(ans, cnt);
    }
    cout << ans + 1;
    return 0;
}