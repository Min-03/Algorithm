#include <bits/stdc++.h>
using namespace std;

string pats[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    cin >> str;
    for (string pat : pats) {
        str = regex_replace(str, regex(pat), ".");
    }
    cout << str.length();
    return 0;
}