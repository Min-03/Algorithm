#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string input;
    getline(cin, input);
    if (input == " ") {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == ' ' && (i != 0 && i != input.length() - 1)) cnt += 1;
    }
    cout << cnt + 1;
    return 0;
}