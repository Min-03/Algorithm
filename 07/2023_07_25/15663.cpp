#include <bits/stdc++.h>
using namespace std;
int n, m;
int choose[8];
int nums[8];
int cnt[10'001];

void printChoose(int chooseNum) {
    if (chooseNum == m) {
        for (int i = 0; i < m; i++) {
            cout << choose[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[nums[i]] == 0 || (i != 0 && nums[i - 1] == nums[i])) {
            continue;
        }
        cnt[nums[i]] -= 1;
        choose[chooseNum] = nums[i];
        printChoose(chooseNum + 1);
        cnt[nums[i]] += 1;
    }
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        cnt[nums[i]] += 1;
    }
    sort(nums, nums + n);
    printChoose(0);
}