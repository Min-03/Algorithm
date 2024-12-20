#include <bits/stdc++.h>
using namespace std;
int choose[8];
int n, m;
void printChoose(int chooseNum) {
    if (chooseNum == m) {
        for (int i = 0; i < m; i++) {
            cout << choose[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (chooseNum != 0 && i < choose[chooseNum - 1]) {
            continue;
        }
        choose[chooseNum] = i;
        printChoose(chooseNum + 1);
    }
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    printChoose(0);
}