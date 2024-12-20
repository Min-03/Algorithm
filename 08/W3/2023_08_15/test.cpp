#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int pow_iter(int a, int b) {
    int ret = 1;
    while (b != 0) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}


int main() {
    FastIO
//    cout << pow_iter(5, 10);
    char ch = 'a';
    string test(1, ch);
    sort(test.begin(),test.end(), greater<char>());
//    cout << test;
    cout << typeid(pow(1, 3)).name() << ' ' << typeid(test).name();
    return 0;
}