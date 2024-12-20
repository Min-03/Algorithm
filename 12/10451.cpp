#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> graph[1'001];
int type[1'001];

bool isCycle(int curr) {
    type[curr] = 1;
    for (int ngb : graph[curr]) {
        if (type[ngb] == 1) return true;
        if (type[ngb] == 0 && isCycle(ngb)) return true;
    }
    type[curr] = 2;
    return false;
}

int main() {
    FASTIO
    int tc;
    cin >> tc;
    while(tc--) {
        int n, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
            type[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            graph[i].push_back(num);
        }

        for (int i = 1; i <= n; i++) {
            if (type[i] == 0 && isCycle(i)) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}