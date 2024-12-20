#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = 0x3f3f3f3f;

bool isPalindrome[2500][2500];
int cnt[2500];

int main() {
    FastIO
    string str;
    cin >> str;
    int n = str.size();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) isPalindrome[i][j] = true;
            else if (i + 1 == j) isPalindrome[i][j] = str[i] == str[j];
            else isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && str[i] == str[j];
        }
    }

    memset(cnt, inf, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (!isPalindrome[i][j]) continue;
            if (i == 0) cnt[j] = 1;
            else cnt[j] = min(cnt[j], cnt[i - 1] + 1);
        }
    }
    cout << cnt[n - 1];
    return 0;
}