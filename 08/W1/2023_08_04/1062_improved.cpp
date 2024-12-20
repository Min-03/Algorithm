#include <bits/stdc++.h>
using namespace std;

bool choose[26];
bool used[50][26];
int n, k, ans = 0;

int ord(char ch) {
    return ch - 'a';
}

int countStr() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < 26; j++) {
            if (used[i][j] && !choose[j]) {
                ok = false;
                break;
            }
        }
        if (ok) cnt += 1;
    }
    return cnt;
}

void go(int index, int chooseNum) {
    if (chooseNum == k - 5) {
        int cnt = countStr();
        ans = max(ans, cnt);
        return;
    }
    if (index == 26 || (26 - index) + chooseNum < k - 5) return;
    if (index == ord('n') || index == ord('t') || index == ord('i') || index == ord('c')) {
        go(index + 1, chooseNum);
    } else {
        choose[index] = true;
        go(index + 1, chooseNum + 1);
        choose[index] = false;
        go(index + 1, chooseNum);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (char ch : str) {
            int pos = ch - 'a';
            used[i][pos] = true;
        }
    }
    if (k < 5) {
        cout << 0;
        return 0;
    }
    choose[ord('a')] = choose[ord('n')] = choose[ord('t')] = choose[ord('i')] = choose[ord('c')] = true;
    go(1, 0);
    cout << ans;
    return 0;
}