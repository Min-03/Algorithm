#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

string strs[1000];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    int k = 1, len = strs[0].length();
    while (true) {
        set<string> used;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            string newStr = strs[i].substr(len - k, k);
            if (used.find(newStr) != used.end()) {
                ok = false;
                break;
            }
            used.insert(newStr);
        }
        if (ok) break;
        else k++;
    }
    cout << k;
    return 0;
}