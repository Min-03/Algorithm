#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[2000][2000];
int arr[2000];

bool isPalindrome(int s, int e) {
    if (s == e) {
        return true;
    } else if (e == s + 1) {
        return arr[s] == arr[e];
    }
    if (dp[s][e] != -1) {
        return dp[s][e] == 1;
    }
    return dp[s][e] = isPalindrome(s + 1, e - 1) && arr[s] == arr[e];
}

int main() {
    FastIO
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    memset(dp, -1, sizeof(dp));
    while (m--) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        cout << (isPalindrome(s, e) ? 1 : 0) << '\n';
    }
    return 0;
}