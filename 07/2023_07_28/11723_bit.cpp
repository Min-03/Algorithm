#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s = 0;
    int m;
    cin >> m;
    while (m--) {
        string cmd;
        cin >> cmd;
        int x;
        if (cmd == "add") {
            cin >> x;
            s = s | (1 << x);
        } else if (cmd == "remove") {
            cin >> x;
            s = s & ~(1 << x);
        } else if (cmd == "check") {
            cin >> x;
            cout << (((s & (1 << x)) == 0) ? 0 : 1) << '\n';
        } else if (cmd == "toggle") {
            cin >> x;
            s = s ^ (1 << x);
        } else if (cmd == "all") {
            s = (1 << 21) - 1;
        } else {
            s = 0;
        }
    }
    return 0;
}
