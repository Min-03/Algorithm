#include <bits/stdc++.h>

using namespace std;
char candies[50][50];
int countCandies(int n) {
    int out = 1;
    //각 행별로 확인
    for (int i = 0 ; i < n; i++) {
        int temp = 1;
        for (int j = 1; j < n; j++) {
            if (candies[i][j - 1] == candies[i][j]) {
                temp += 1;
            } else {
                temp = 1;
            }
            out = max(out, temp);
        }
    }
    //각 열별로 확인
    for (int j = 0 ; j < n; j++) {
        int temp = 1;
        for (int i = 1; i < n; i++) {
            if (candies[i - 1][j] == candies[i][j]) {
                temp += 1;
            } else {
                temp = 1;
            }
            out = max(out, temp);
        }
    }
    return out;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> candies[i][j];
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < n - 1) {
                swap(candies[i][j], candies[i + 1][j]);
                ans = max(ans, countCandies(n));
                swap(candies[i][j], candies[i + 1][j]);
            }
            if (j < n - 1) {
                swap(candies[i][j], candies[i][j + 1]);
                ans = max(ans, countCandies(n));
                swap(candies[i][j], candies[i][j + 1]);
            }
        }
    }
    cout << ans;
}