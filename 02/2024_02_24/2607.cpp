#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cntAns[26], cntIn[26];

bool ok() {
    int add = 0, remove = 0;
    for (int i = 0; i < 26; i++) {
        if (abs(cntAns[i] - cntIn[i]) >= 2) return false;
        if (cntAns[i] > cntIn[i]) add += 1;
        else if (cntAns[i] < cntIn[i]) remove += 1;
    }
    return add + remove <= 1 || add == remove && remove == 1;
}

int main() {
    FastIO
    string ans, in;
    int n, cnt = 0;
    cin >> n;
    cin >> ans;
    for (char ch : ans) cntAns[ch - 'A']++;
    for (int i = 1; i < n; i++) {
        memset(cntIn, 0, sizeof(cntIn));
        cin >> in;
        for (char ch : in) cntIn[ch - 'A']++;
        if (ok()) cnt++;
    }
    cout << cnt;
    return 0;
}