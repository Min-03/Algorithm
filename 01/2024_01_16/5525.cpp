#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    vector<int> lens;
    int n, m, numI = 0;
    string str;
    cin >> n >> m >> str;
    for (int i = 0; i < str.length(); i++) {
        if (numI != 0 && str[i - 1] == str[i]) {
            lens.push_back(numI - 1);
            numI = 0;
        }
        if (str[i] == 'I') numI++;
    }
    if (numI != 0) lens.push_back(numI - 1);

    int ans = 0;
    for (int len : lens) {
        if (n <= len) ans += len - n + 1;
    }
    cout << ans;
    return 0;
}