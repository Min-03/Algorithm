#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool spoiled[101];

int main() {
    FastIO
    int n;
    cin >> n;
    cout << n - 1 << endl;
    for (int i = 1; i <= n - 1; i++) {
        cout << i << ' ';
        for (int j = 1; j <= i; j++) {
            cout << j << ' ';
        }
        cout << endl;
    }
    bool flag = false;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            spoiled[i + 1] = true;
            flag = true;
        }
    }
    if (!flag) spoiled[n] = true;
    for (int i = 1; i <= n; i++) {
        if (spoiled[i]) {
            cout << i << endl;
            return 0;
        }
    }
}