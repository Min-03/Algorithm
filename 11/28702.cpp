#include <bits/stdc++.h>
#define FASTIO sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string getString(int i) {
    if (i % 3 == 0 && i % 5 == 0) return "FizzBuzz";
    if (i % 3 == 0) return "Fizz";
    if (i % 5 == 0) return "Buzz";
    return to_string(i);
}

int main() {
    for (int i = 3; i > 0; i--) {
        string ans;
        cin >> ans;
        if (isdigit(ans[0])) {
            cout << getString(stoi(ans) + i);
            return 0;
        }
    }
}