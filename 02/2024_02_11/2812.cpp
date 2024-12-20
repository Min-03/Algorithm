#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

stack<int> pos[10];

int main() {
    FastIO
    int n, k;
    string str;
    cin >> n >> k >> str;
    for (int i = n - 1; i >= 0; i--) {
        int num = str[i] - '0';
        pos[num].push(i);
    }
    int left = k, idx = 0;
    for (int i = 0; i < n - k; i++) {
        for (int j = 9; j >= 0; j--) {
            while (!pos[j].empty() && pos[j].top() < idx) pos[j].pop();
        }

        for (int j = 9; j >= 0; j--) {
            if (!pos[j].empty() && pos[j].top() - idx <= left) {
                cout << j;
                left -= pos[j].top() - idx;
                idx = pos[j].top() + 1;
                break;
            }
        }
    }
    return 0;
}