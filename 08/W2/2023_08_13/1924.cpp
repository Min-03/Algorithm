#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int toDay(int month) {
    month--;
    int ret = 0;
    while (month > 0) {
        switch(month) {
            case 4:
            case 6:
            case 9:
            case 11:
                ret += 30;
                break;
            case 2:
                ret += 28;
                break;
            default:
                ret += 31;
                break;
        }
        month--;
    }
    return ret;
}

int main() {
    FastIO
    int month, day;
    cin >> month >> day;
    string yoIl[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int res = (toDay(month) + day) % 7;
    cout << yoIl[res];
    return 0;
}