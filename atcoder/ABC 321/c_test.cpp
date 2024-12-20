#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool check(long long num) {
    string str = to_string(num);
    for (int i = 1; i <= str.length(); i++) {
        if (str[i] >= str[i - 1]) return false;
    }
    return true;
}

int main() {
    FastIO
    int k;
    cin >> k;
    long long num = 1;
    while (k > 0) {
        if (check(num)) k--;
        num++;
    }
    cout << num - 1;
    return 0;
}