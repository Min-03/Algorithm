#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": ";
        if (n <= 25) {
            cout << "World Finals\n";
        } else if (n <= 1000) {
            cout << "Round 3\n";
        } else if (n <= 4500) {
            cout << "Round 2\n";
        } else {
            cout << "Round 1\n";
        }
    }
    return 0;
}