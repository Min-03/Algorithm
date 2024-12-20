#include <bits/stdc++.h>
using namespace std;
int n;
int pays[16];
int times[16];
int go(int day,int left) {
    if (day == n + 1 && left >= 0) {
        return 0;
    } else if (left < 0) {
        return -1;
    }
    int pay = 0;
    //day번째 있는 상담을 함
    int temp = go(day + times[day], left - times[day]);
    if (temp != -1) {
        pay = temp + pays[day];
    }
    //day번째 있는 상담을 안 함
    pay = max(pay, go(day + 1, left - 1));
    return pay;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> times[i] >> pays[i];
    }
    cout << go(1, n);
    return 0;
}
