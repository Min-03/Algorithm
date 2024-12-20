#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nums[1001], lidx[1001], ridx[1001];

int goLeft(int start, int moveNum) {
    int curr = start;
    for (int i = 0; i < moveNum; i++) {
        curr = lidx[curr];
    }
    return curr;
}

int goRight(int start, int moveNum) {
    int curr = start;
    for (int i = 0; i < moveNum; i++) {
        curr = ridx[curr];
    }
    return curr;
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 1) lidx[i] = n;
        else lidx[i] = i - 1;
        if (i == n) ridx[i] = 1;
        else ridx[i] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    int del = 0, curr = 1;
    while (del != n) {
        cout << curr << ' ';
        ridx[lidx[curr]] = ridx[curr];
        lidx[ridx[curr]] = lidx[curr];
        int nxt;
        if (nums[curr] > 0) nxt = goRight(curr, nums[curr]);
        else nxt = goLeft(curr, -nums[curr]);
        curr = nxt;
        del++;
    }
    return 0;
}