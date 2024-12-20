#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

char graph[20][20];
bool rowChoose[20];
int n, ans = 400; //T의 최솟값

char flip(char ch) {
    if (ch == 'H') return 'T';
    else return 'H';
}

int calTails() {
    char temp[20][20];
    memcpy(temp, graph, sizeof(graph));
    for (int i = 0; i < n; i++) {
        if (rowChoose[i]) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = flip(temp[i][j]);
            }
        }
    }

    int ret = 0;
    for (int j = 0; j < n; j++) {
        int tails = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i][j] == 'T') tails += 1;
        }
        ret += min(tails, n - tails);
    }
    return ret;
}

void go(int index) {
    if (index == n) {
        ans = min(ans, calTails());
        return;
    }
    rowChoose[index] = true;
    go(index + 1);
    rowChoose[index] = false;
    go(index + 1);
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    go(0);
    cout << ans;
    return 0;
}