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
        bool skip = false;
        for (int j = 0; j < chooseNum; j++) {
            if (choose[j] == i) {
                skip = true;
                break;
            }
        }
        if (!skip) {
            choose[chooseNum] = i;
            printChoose(chooseNum + 1);
        }
    }
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    printChoose(0);
}