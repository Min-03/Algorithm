#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        multiset<int> s;
        while (k--) {
            char ch;
            int num;
            cin >> ch >> num;
            if (ch == 'I') {
                s.insert(num);
            } else {
                if (s.empty()) continue;
                if (num == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *(--s.end()) << ' ' << *s.begin() << "\n";
        }
    }
    return 0;
}