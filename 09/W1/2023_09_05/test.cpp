#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool test[100];

int main() {
    FastIO
    memset(test, true, sizeof(test));
    for (int i = 0; i < 100; i++) {
        cout << test[i] << '\n';
    }
    return 0;
}