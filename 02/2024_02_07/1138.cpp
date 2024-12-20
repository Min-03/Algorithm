#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> heights;
int cnts[11];
int n;

bool check() {
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (heights[j] > heights[i]) cnt++;
        }
        if (cnts[heights[i]] != cnt) return false;
    }
    return true;
}

int main() {
    FastIO
    cin >> n;
    heights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cnts[i + 1];
        heights[i] = i + 1;
    }
    do {
        if (!check()) continue;
        for (int i = 0; i < n; i++) cout << heights[i] << ' ';
        break;
    } while (next_permutation(heights.begin(), heights.end()));
    return 0;
}