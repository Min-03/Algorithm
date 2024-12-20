#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int test[4];

int main() {
    FastIO
    memset(test, 0x3f, sizeof(test));
    for (int i = 0; i < 4; i++) {
        cout << test[i] << ' ';
    }
    cout << '\n';
    if (test[0] == 0x3f3f3f3f) {
        cout << "go\n";
    }
    return 0;
}