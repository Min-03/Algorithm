#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dists[1'000'001], cnts[10];
int len, k;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    dists[st] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                string str = to_string(curr);
                swap(str[i], str[j]);
                int nxt = stoi(str);
                if (str[0] == '0' || dists[nxt] != -1 || dists[curr] >= k) continue;
                q.push(nxt);
                dists[nxt] = dists[curr] + 1;
            }
        }
    }
}

int main() {
    FastIO
    string str;
    int n = 0, nonZero = 0, hi = -1;
    bool same = false;
    cin >> str >> k;
    len = str.size();
    for (char ch : str) {
        int num = ch - '0';
        if (num != 0) nonZero++;
        n = n * 10 + num;
        cnts[num]++;
    }
    for (int i = 0; i <= 9; i++) if (cnts[i] >= 2) same = true;
    if (!same && nonZero <= 1) {
        cout << -1;
        return 0;
    }
    memset(dists, -1, sizeof(dists));
    bfs(n);
    for (int i = 0; i <= 1'000'000; i++) {
        if (dists[i] == -1 || !same && ((k - dists[i]) & 1)) continue;
        hi = max(hi, i);
    }
    cout << hi;
    return 0;
}