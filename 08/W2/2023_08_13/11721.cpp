#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string input;
    cin >> input;
    int length = input.length();
    for (int i = 0; i <= length - 10; i += 10) {
        printf("%s\n", input.substr(i, 10).c_str());
    }
    if (length % 10 != 0) {
        printf("%s\n", input.substr(length - length % 10).c_str());
    }
    return 0;
}