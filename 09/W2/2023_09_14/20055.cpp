#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> robots;
bool used[201], temp[201];
int armors[201];
int breaks = 0;

int main() {
    FastIO
    int n, k;
    cin >> n >> k;
    robots.reserve(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> armors[i];
    }
    int step = 1;
    while (breaks < k) {
        cout << step << ' ' << breaks << '\n';
        memcpy(temp, used, sizeof(used));
        for (int i = 0; i < 2 * n; i++) {
            if (temp[(i - 1 + 2 * n) % (2 * n)]) used[i] = true;
        }
        for (int i = 0; i < robots.size(); i++) {
            int curr = (robots[i] + step - 1) % (2 * n);
            int next = (curr + 1) % (2 * n);
            if (!used[next] && armors[next] > 0) {
                used[curr] = false;
                used[next] = true;
                armors[next]--;
                if (armors[next] == 0) breaks++;
                robots[i] = (i + 1) % (2 * n);
            }
        }
        if (armors[0] > 0) {
            robots.push_back(0);
            armors[0]--;
            if (armors[0] == 0) breaks++;
        }
        step++;
    }
    cout << step;
    return 0;
}