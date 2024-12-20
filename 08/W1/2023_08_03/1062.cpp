#include <bits/stdc++.h>
using namespace std;

bool choose[26];
string strs[50];
int n, k, ans = 0;

int calNum() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (char ch : strs[i]) {
            if (!choose[ch - 'a']) {
                ok = false;
                break;
            }
        }
        if (ok) cnt += 1;
    }
    return cnt;
}

int ord(char ch) {
    return ch - 'a';
}

void go(int index, int chooseNum) {
    if (chooseNum == k) {
        //단어 개수 계산
        ans = max(calNum(), ans);
        return;
    } else if (index == 26 || 26 - index + chooseNum < k || chooseNum > k) {
        return;
    }
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
        cin >> strs[i];
    }
    if (k < 5) {
        cout << 0;
        return 0;
    }
    k -= 5;
    choose[ord('a')] = choose[ord('n')] = choose[ord('t')] = choose[ord('i')] = choose[ord('c')] = true;
    go(1, 0);
    cout << ans;
    return 0;
}