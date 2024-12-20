#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    vector<bool> submit(31);
    for (int i = 0; i < 28; i++) {
        int num;
        cin >> num;
        submit[num] = true;
    }
    for (int i = 1; i <= 30; i++) {
        if (!submit[i]) cout << i << '\n';
    }
    return 0;
}