#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> um;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char test[] = {'+', '-', '*', '/'};
    sort(test, test + 4);
    for (char ch : test) {
        cout << ch << ' ';
    }
    return 0;
}