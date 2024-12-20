#include <bits/stdc++.h>

using namespace std;
int stats[20][20];
int choose[10];
int n, diff = 1e9;

void updateDiff() {
    int scoreS = 0, scoreL = 0;
    //각 팀에 들어갈 선수 정함
    vector<int> link;
    vector<int> start;
    for (int i = 0; i < n; i++) {
        if (find(choose, choose + n / 2, i) != choose + n / 2) {
            start.push_back(i);
        } else {
            link.push_back(i);
        }
    }
    for (int i : start) {
        for (int j : start) {
            scoreS += stats[i][j];
        }
    }
    for (int i : link) {
        for (int j : link) {
            scoreL += stats[i][j];
        }
    }
    diff = min(diff, abs(scoreS - scoreL));
}

//스타트 팀에 들어갈 선수를 정함
void divideTeam(int curr, int chooseNum) {
    if (chooseNum == n / 2) {
        updateDiff();
        return;
    } else if (curr >= n) {
        return;
    }
    choose[chooseNum] = curr;
    divideTeam(curr + 1, chooseNum + 1);
    divideTeam(curr + 1, chooseNum);
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stats[i][j];
        }
    }
    divideTeam(0, 0);
    cout << diff;
    return 0;
}