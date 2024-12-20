#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> players[11]; //players[i] = {stat, pos}
bool used[11];
int ans = 0;

void go(int curr, int sum) {
    if (curr == 11) {
        ans = max(ans, sum);
        return;
    }
    for (const auto& [stat, pos] : players[curr]) {
        if (!used[pos]) {
            used[pos] = true;
            go(curr + 1, sum + stat);
            used[pos] = false;
        }
    }
}

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        for (int i = 0; i < 11; i++) {
            players[i].clear();
        }
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                int stat;
                cin >> stat;
                if (stat != 0) {
                    players[i].push_back({stat, j});
                }
            }
        }
        go(0, 0);
        cout << ans << '\n';
    }
    return 0;
}