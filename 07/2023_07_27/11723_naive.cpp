#include <bits/stdc++.h>
bool check[21];
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;
    while (m--) {
        string cmd;
        cin >> cmd;
        int x;
        if (cmd == "add") {
            cin >> x;
            check[x] = true;
        } else if (cmd == "remove") {
            cin >> x;
            check[x] = false;
        } else if (cmd == "check") {
            cin >> x;
            cout << check[x] << '\n';
        } else if (cmd == "toggle") {
            cin >> x;
            check[x] = !check[x];
        } else if (cmd == "all") {
            fill(check + 1, check + 21, 1);
        } else {
            fill(check + 1, check + 21, 0);
        }
    }
    return 0;
}