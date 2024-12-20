#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string line;
    getline(cin, line);
    while (line != "#") {
        int vowel = 0;
        for (char ch : line) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowel++;
        }
        cout << vowel << '\n';
        getline(cin, line);
    }
    return 0;
}