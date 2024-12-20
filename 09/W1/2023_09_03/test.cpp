#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int test[10][10];

int main() {
    FastIO
    fill(&test[0][0], &test[0][0] + sizeof(test), 3);
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cout << test[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}