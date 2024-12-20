#include <bits/stdc++.h>
using namespace std;
char sign[10][10];
int choose[10];
bool found;
int n;
bool check(int index, int num) {
    choose[index] = num;
    int sum = 0;
    for (int i = index; i >= 0; i--) {
        sum += choose[i];
        if (sign[i][index] == '0' && sum != 0) {
            return false;
        } else if (sign[i][index] == '+' && sum <= 0) {
            return false;
        } else if (sign[i][index] == '-' && sum >= 0) {
            return false;
        }
    }
    return true;
}
void go(int curr) {
    if (found) return;
    if (curr == n) {
        for (int i = 0; i < n; i++) {
            cout << choose[i] << ' ';
        }
        found = true;
        return;
    }
    if (sign[curr][curr] == '0') {
        choose[curr] = 0;
        go(curr + 1);
    } else if (sign[curr][curr] == '+') {
        for (int i = 1; i <= 10; i++) {
            if (!check(curr, i)) {
                continue;
            }
            choose[curr] = i;
            go(curr + 1);
        }
    } else {
        for (int i = 1; i <= 10; i++) {
            if (!check(curr, -i)) {
                continue;
            }
            choose[curr] = -i;
            go(curr + 1);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> sign[i][j];
        }
    }
    go(0);
    return 0;
}