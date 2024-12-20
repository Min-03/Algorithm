#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> mustHave;
int ans = 0, n;

void go(const string& s, int usedNum) {
    if (s.length() == n) {
        for (int num : mustHave) {
            if (!(usedNum & (1 << num))) return;
        }
        ans++;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        char nxt = i + '0';
        int nxtNums = usedNum | (1 << i);
        go(s + nxt, nxtNums);
    }
}

int main() {
    FastIO
    int m;
    cin >> n >> m;
    while (m--) {
        int num;
        cin >> num;
        mustHave.push_back(num);
    }
    for (int i = 0; i <= 9; i++) {
        char nxt = i + '0';
        int nxtNums = (1 << i);
        go(string(1, nxt), nxtNums);
    }
    cout << ans;
    return 0;
}