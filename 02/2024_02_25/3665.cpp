#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[501];
bool isFirst[501][501];
int inDegrees[501];

void init(int n) {
    memset(isFirst, 0, sizeof(isFirst));
    for (int i = 1; i <= n; i++) {
        inDegrees[i] = 0;
        graph[i].clear();
    }
}

void topological(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegrees[i] == 0) q.push(i);
    }
    vector<int> res;
    while (!q.empty()) {
        if (q.size() != 1) {
            cout << "?\n";
            return;
        }
        int curr = q.front(); q.pop();
        res.push_back(curr);
        for (int ngb : graph[curr]) {
            if (--inDegrees[ngb] == 0) q.push(ngb);
        }
    }
    if (res.size() != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i : res) cout << i << ' ';
    cout << '\n';
}

int main() {
    FastIO
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n;
        init(n);
        vector<int> vec(n);
        for (int &i : vec) cin >> i;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) isFirst[vec[i]][vec[j]] = true;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            swap(isFirst[a][b], isFirst[b][a]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (isFirst[i][j]) {
                    graph[i].push_back(j);
                    inDegrees[j]++;
                }
            }
        }
        topological(n);
    }
    return 0;
}