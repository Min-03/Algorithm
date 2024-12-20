#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool isNotSelf[10'001];

int getDigits(int num) {
    string numStr = to_string(num);
    int ret = 0;
    for (char ch : numStr) {
        ret += ch - '0';
    }
    return ret;
}

int main() {
    FastIO
    for (int i = 1; i <= 10'000; i++) {
        int next = i + getDigits(i);
        if (next <= 10'000) isNotSelf[next] = true;
        if (!isNotSelf[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}