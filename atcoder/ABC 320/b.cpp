#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

string str;

bool check(int start, int end) {
    int l = start, r = end;
    while (l <= r) {
        if (str[l] != str[r]) return false;
        l++, r--;
    }
    return true;
}

int main() {
    FastIO
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            if (j < i) continue;
            if (check(i, j)) ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
    return 0;
}