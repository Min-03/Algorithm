#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int nxt[500'001];
bool isStart[500'001];
map<int, string> names;

int main() {
    FastIO
    int n, st;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        names[i] = name;
    }
    for (int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        nxt[s] = e;
        isStart[e] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (isStart[i]) {
            st = i;
            break;
        }
    }
    int curr = st;
    while (curr) {
        cout << names[curr];
        curr = nxt[curr];
    }
    return 0;
}