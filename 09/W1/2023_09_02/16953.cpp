#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int inf = (int) 1e9;

string a, b;
int ans = inf;

void go(string &curr, int cnt) {
    if (curr.length() == 0) return;
    if (curr == a) {
        ans = min(ans, cnt);
        return;
    }
    if (curr.back() == '1') {
        curr.pop_back();
        go(curr, cnt + 1);
        return;
    }
    int num = stoi(curr);
    if ((num & 1) == 0) {
        string str = to_string(num / 2);
        go(str, cnt + 1);
    }
}

int main() {
    FastIO
    cin >> a >> b;
    go(b, 1);
    cout << (ans == inf ? -1 : ans);
    return 0;
}