#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char chars[5][16];

int main() {
    FastIO
    for (int i = 0; i < 5; i++) {
        cin >> chars[i];
    }
    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            if (chars[i][j] != '\0') cout << chars[i][j];
        }
    }
    return 0;
}