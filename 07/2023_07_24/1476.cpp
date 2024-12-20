#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int subYear[3];
    int ans[3];
    for (int i = 0; i < 3; i++) {
        cin >> ans[i];
    }
    int year = 1;
    while (true) {
        subYear[0] = (year % 15 == 0) ? 15 : year % 15;
        subYear[1] = (year % 28 == 0) ? 28 : year % 28;
        subYear[2] = (year % 19 == 0) ? 19 : year % 19;
        if (equal(subYear, subYear + 3, ans)) {
            cout << year;
            break;
        }
        year++;
    }

    return 0;
}
