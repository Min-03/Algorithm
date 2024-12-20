#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<string> types;
map<string, int> cnts;

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        types.clear();
        cnts.clear();
        int n;
        cin >> n;
        if (n == 0) {
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            string foo, type;
            cin >> foo >> type;
            if (cnts[type] == 0) types.push_back(type);
            cnts[type] += 1;
        }

        int ans = 1;
        for (string &type : types) {
            ans *= cnts[type] + 1;
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}