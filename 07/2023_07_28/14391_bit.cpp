#include <bits/stdc++.h>
using namespace std;
int num[4][4];
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < m; j++) {
            num[i][j] = numStr[j] - '0';
        }
    }

    int score = 0;
    // 0: 세로, 1: 가로
    for (int set = 0; set < (1 << (n * m)); set++) {
        int currScore = 0;
        for (int i = 0; i < n; i++) {
            string numStr = "0";
            for (int j = 0; j < m; j++) {
                int pos = i * m + j;
                if ((set & (1 << pos)) != 0) {
                    numStr += num[i][j] + '0';
                } else {
                    currScore += stoi(numStr);
                    numStr = "0";
                }
            }
            currScore += stoi(numStr);
        }

        for (int j = 0; j < m; j++) {
            string numStr = "0";
            for (int i = 0; i < n; i++) {
                int pos = i * m + j;
                if ((set & (1 << pos)) == 0) {
                    numStr += num[i][j] + '0';
                } else {
                    currScore += stoi(numStr);
                    numStr = "0";
                }
            }
            currScore += stoi(numStr);
        }
        score = max(score, currScore);
    }
    cout << score;
    return 0;
}