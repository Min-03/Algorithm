#include <bits/stdc++.h>
using namespace std;
vector<string> ansVec;
int choose[10];
char ops[9];
bool used[10];
int k;
bool check(int before, int curr, char op) {
    if (op == '<') {
        return before < curr;
    } else {
        return before > curr;
    }
}
void go(int curr) {
    if (curr == k + 1) {
        string numStr;
        for (int i = 0; i < curr; i++) {
            numStr += choose[i] + '0';
        }
        ansVec.push_back(numStr);
        return;
    }
    if (curr > k + 1) {
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (used[i] || (curr != 0 && !check(choose[curr - 1], i, ops[curr - 1]))) continue;
        choose[curr] = i;
        used[i] = true;
        go(curr + 1);
        used[i] = false;
    }

}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ops[i];
    }
    go(0);
    cout << ansVec.back() << '\n';
    cout << ansVec.at(0) << '\n';
    return 0;
}