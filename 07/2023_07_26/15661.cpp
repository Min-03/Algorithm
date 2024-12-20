#include <bits/stdc++.h>

using namespace std;
int stats[20];
int choose[20];
int n, sum = 0, diff = 1e9;

void updateDiff(int startPeople) {
    int localDiff = sum;
    for (int i = 0; i < startPeople; i++) {
        localDiff -= stats[choose[i]];
    }
    diff = min(diff, abs(localDiff));
}

//스타트 팀에 들어갈 선수를 정함
void divideTeam(int curr, int chooseNum) {
    if (1 <= chooseNum && chooseNum <= n - 1) {
        updateDiff(chooseNum);
    }
    if (curr >= n) {
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
            int stat;
            cin >> stat;
            stats[i] += stat;
            stats[j] += stat;
            sum += stat;
        }
    }
    divideTeam(0, 0);
    cout << diff;
    return 0;
}