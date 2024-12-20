#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int mod = 1e6;

string str;
int dp[5001];

int main() {
    FastIO
    cin >> str;
    str = ' ' + str;
    dp[0] = 1;
    for (int i = 1; i < str.size(); i++) {
        if (i > 1 && stoi(str.substr(i - 1, 2)) <= 26) {
            if (str[i] == '0') {
                dp[i - 1] = 0;
                dp[i] = dp[i - 2];
            } else dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
        } else {
            if (str[i] == '0') {
                cout << 0;
                return 0;
            }
            else dp[i] = dp[i - 1];
        }
    }
    cout << dp[str.size() - 1];
    return 0;
}