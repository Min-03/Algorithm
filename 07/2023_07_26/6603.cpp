#include <bits/stdc++.h>
using namespace std;
int choose[6];
int num[12];
int n;
void go(int currIndex, int chooseNum) {
    if (chooseNum == 6) {
        for (int i = 0; i < 6; i++) {
            cout << choose[i] << ' ';
        }
        cout << '\n';
        return;
    } else if (currIndex >= n) {
        return;
    }
    choose[chooseNum] = num[currIndex];
    go(currIndex + 1, chooseNum + 1);
    go(currIndex + 1, chooseNum);
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        cin >> n;
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(num, num + n);
        go(0, 0);
        cout << '\n';
    }
    return 0;
}