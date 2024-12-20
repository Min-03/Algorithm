#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
char graph[21][21];

pii getMoved(pii curr, string dir) {
    pii moved(curr);
    if (dir == "up") {
        moved.first = curr.first - 1;
    } else if (dir == "down") {
        moved.first = curr.first + 1;
    } else if (dir == "left") {
        moved.second = curr.second - 1;
    } else {
        moved.second = curr.second + 1;
    }

    if (graph[moved.first][moved.second] == '#') {
        return curr;
    } else {
        return moved;
    }
}


//눌러야 하는 최소 횟수 반환, 10번 안에 해결이 안 되면, 11 반환
int go(int tried, pii coinA, pii coinB) {
    if (tried > 10) return 11;
    //coinA와 coinB가 판 안에 있는지 확인
    bool dropA = false, dropB = false;
    if (coinA.first <= 0 || coinA.first > n || coinA.second <= 0 || coinA.second > m) {
        dropA = true;
    }
    if (coinB.first <= 0 || coinB.first > n || coinB.second <= 0 || coinB.second > m) {
        dropB = true;
    }

    if (dropA && dropB) {
        return 11;
    } else if (dropA || dropB) {
        return tried;
    }

    int movedNum = 11;
    string dirs[] = {"up", "down", "left", "right"};
    for (string dir : dirs) {
        pii resA = getMoved(coinA, dir);
        pii resB = getMoved(coinB, dir);
        movedNum = min(movedNum, go(tried + 1, resA, resB));
    }
    return movedNum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    vector<pii> coins;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'o') {
                coins.emplace_back(i, j);
            }
        }
    }

    int res = go(0, coins[0], coins[1]);
    cout << (res == 11 ? -1 : res);
    return 0;
}