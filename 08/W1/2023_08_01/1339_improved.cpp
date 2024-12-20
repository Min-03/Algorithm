#include <bits/stdc++.h>
using namespace std;

int freq[26];
string strs[10];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        int length = strs[i].length();
        for (int j = 0; j < length; j++) {
            char ch = strs[i][j];
            freq[ch - 'A'] += pow(10, length - j - 1);
        }
    }
    sort(freq, freq + 26, greater<int>());
    int ans = 0, index = 0;
    while (freq[index] != 0) {
        ans += freq[index] * (9 - index);
        index += 1;
    }
    cout << ans;
    return 0;
}