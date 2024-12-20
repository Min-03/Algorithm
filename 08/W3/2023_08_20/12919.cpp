#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool go(string &end, string &curr) {
    if (end.length() == curr.length()) {
        return end == curr;
    }
    char front = curr[0];
    char back = curr.back();
    if (front == 'A') {
        if (back == 'A') {
            curr.pop_back();
            return go(end, curr);
        } else {
            return false;
        }
    } else {
        string temp = curr.substr(1);
        reverse(temp.begin(), temp.end());
        if (back == 'A') {
            bool res1 = go(end, temp);
            curr.pop_back();
            bool res2 = go(end, curr);
            return res1 || res2;
        } else {
            return go(end, temp);
        }
    }
}

int main() {
    FastIO
    string s, t;
    cin >> s >> t;
    cout << (go(s, t) ? 1 : 0);
    return 0;
}