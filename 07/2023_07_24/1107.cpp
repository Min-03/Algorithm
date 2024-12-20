#include <bits/stdc++.h>

using namespace std;
bool banned[10];

bool possible(int n) {
    string numStr = to_string(n);
    int length = numStr.length();
    for (int i = 0; i < length; i++) {
        int currDigit = numStr[i] - '0';
        if (banned[currDigit]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        banned[num] = 1;
    }
    int ans = abs(n - 100);
    for (int i = 0; i <= 1'000'000; i++) {
        if (!possible(i)) continue;
        int numPress = to_string(i).length();
        int opPress = abs(n - i);
        ans = min(ans, numPress + opPress);
    }
    cout << ans;
}