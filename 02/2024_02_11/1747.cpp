#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isDivided[2'000'001];

bool isPalindrome(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

int main() {
    FastIO
    isDivided[0] = true;
    isDivided[1] = true;
    for (int i = 2; i * i <= 2'000'000; i++) {
        if (isDivided[i]) continue;
        for (int j = 2 * i; j <= 2'000'000; j += i) {
            isDivided[j] = true;
        }
    }
    int n;
    cin >> n;
    while (true) {
        if (!isDivided[n] && isPalindrome(n)) {
            cout << n;
            return 0;
        }
        n++;
    }
}