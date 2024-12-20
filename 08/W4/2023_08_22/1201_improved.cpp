#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void printNums(int begin, int end) {
    for (int i = end - 1; i >= begin; i--) {
        cout << i << ' ';
    }
}

int main() {
    FastIO
    int n, m, k;
    cin >> n >> m >> k;
    if (n < m + k - 1 || n > m * k) {
        cout << -1;
        return 0;
    }
    vector<int> borders;
    borders.push_back(1);
    borders.push_back(k + 1);
    int gs = (m == 1 ? 1 : (n - k) / (m - 1));
    int remain = (m == 1 ? 0 : (n - k) % (m - 1));
    int index = k + 1 + gs;
    while (index <= n) {
        borders.push_back(index);
        index += gs;
        if (remain > 0) index++, remain--;
    }

    for (int i = k; i >= 1; i--) {
        cout << i << ' ';
    }
    for (int i = 1; i < borders.size(); i++) {
        if (i == borders.size() - 1) printNums(borders[i], n + 1);
        else printNums(borders[i], borders[i + 1]);
    }
    return 0;
}