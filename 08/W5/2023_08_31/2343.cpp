#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> lectures;
int n, m;

bool check(int num) {
    int cnt = 1, left = num;
    for (int lecture : lectures) {
        if (lecture <= left) {
            left -= lecture;
        } else {
            cnt++;
            left = num - lecture;
        }
    }
    return cnt <= m;
}

int main() {
    FastIO
    cin >> n >> m;
    lectures.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lectures[i];
    }
    int lo = *max_element(lectures.begin(), lectures.end()) - 1, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
    return 0;
}