#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
    FASTIO
    int n, i = 666, cnt = 0;
    cin >> n;
    while (true) {
        string s = to_string(i);
        if (s.find("666") != string::npos) cnt++;
        if (cnt == n) {
            cout << i;
            return 0;
        }
        i++;
    }
}