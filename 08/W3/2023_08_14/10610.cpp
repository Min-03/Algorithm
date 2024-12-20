#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string numStr;
    cin >> numStr;
    vector<char> digits;
    digits.reserve(1e5);
    int sum = 0;
    for (char ch : numStr) {
        digits.push_back(ch);
        sum += ch - '0';
    }
    sort(digits.begin(), digits.end(), greater<char>());
    if (sum % 3 != 0 || digits.back() - '0' != 0) {
        cout << -1;
        return 0;
    }
    string ans;
    for (char ch : digits) {
        ans += ch;
    }
    cout << ans;
    return 0;
}