#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<char, int> cnts;

int main() {
    FastIO
    int n;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        cnts[ch]++;
    }
    cin >> ch;
    cout << cnts[ch];
    return 0;
}