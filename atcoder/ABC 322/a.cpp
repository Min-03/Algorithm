#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string input;
    int n;
    cin >> n >> input;
    if (input.find("ABC") != string::npos) {
        cout << input.find("ABC") + 1;
        return 0;
    }
    cout << -1;
    return 0;
}