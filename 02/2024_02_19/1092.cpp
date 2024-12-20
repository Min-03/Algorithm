#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int parents[10'001], boxes[10'010], init[51], limits[51];

int find_set(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find_set(parents[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a < b) swap(a, b);
    parents[a] = b;
}

int main() {
    FastIO
    int n, m, hiLimit = 0, hiW = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> limits[i];
        hiLimit = max(hiLimit, limits[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> boxes[i];
        hiW = max(hiW, boxes[i]);
    }
    if (hiLimit < hiW) {
        cout << -1;
        return 0;
    }
    bool check = false;
    sort(boxes + 1, boxes + m + 1);
    for (int i = 0; i <= 10'000; i++) parents[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (limits[i] < boxes[j]) break;
            init[i] = j;
            if (j == m) check = true;
        }
    }
    assert(check);

    int time = 0;
    while (cnt < m) {
        for (int i = 0; i < n; i++) {
            int carry = find_set(init[i]);
            if (carry) {
                cnt++;
                union_set(carry, carry - 1);
            }
        }
        time++;
    }
    cout << time;
    return 0;
}