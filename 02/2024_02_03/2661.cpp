#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n;

bool check(const string &str, char back) {
    int s = str.size(), len = 1;
    while (s + 1 >= 2 * len) {
        bool same = true;
        for (int i = s - len + 1; i <= s; i++) {
            char curr = (i == s ? back : str[i]);
            if (curr != str[i - len]) {
                same = false;
                break;
            }
        }
        if (same) return false;
        len++;
    }
    return true;
}

void go(const string &str) {
    if (str.length() == n) {
        cout << str;
        exit(0);
    }
    for (char nxt : {'1', '2', '3'}) {
        if (check(str, nxt)) go(str + nxt);
    }
}


int main() {
    FastIO
    cin >> n;
    string str = "";
    go("");
    return 0;
}