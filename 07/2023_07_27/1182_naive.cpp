#include <bits/stdc++.h>
using namespace std;
int choose[20];
int nums[20];
int n, s, cnt = 0;
bool equalToSum(int chooseNum) {
    int sum = accumulate(choose, choose + chooseNum, 0);
    return sum == s;
}
void go(int curr, int chooseNum) {
    if (curr == n && chooseNum > 0 && equalToSum(chooseNum)) {
        cnt += 1;
        return;
    }
    if (curr >= n) {
        return;
    }
    choose[chooseNum] = nums[curr];
    go(curr + 1, chooseNum + 1);
    go(curr + 1, chooseNum);
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    go(0, 0);
    cout << cnt;
    return 0;
}