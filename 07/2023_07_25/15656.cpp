#include <bits/stdc++.h>
using namespace std;
int nums[7];
int choose[7];
int n, m;
void printChoose(int chooseNum) {
    if (chooseNum == m) {
        for (int i = 0; i < m; i++) {
            cout << choose[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        choose[chooseNum] = nums[i];
        printChoose(chooseNum + 1);
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    printChoose(0);
    return 0;
}
