#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> squares;

int main() {
    FastIO
    int n, num = 1;
    cin >> n;
    while (num * num <= n) {
        squares.push_back(num * num);
        num++;
    }
    for (int square : squares) {
        if (square == n) {
            cout << 1;
            return 0;
        }
    }

    for (int s1 : squares) {
        for (int s2 : squares) {
            if (s1 + s2 == n) {
                cout << 2;
                return 0;
            }
        }
    }

    for (int s1 : squares) {
        for (int s2 : squares) {
            for (int s3 : squares) {
                if (s1 + s2 + s3 == n) {
                    cout << 3;
                    return 0;
                }
            }
        }
    }
    cout << 4;
    return 0;
}