#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

pair<int, int> val[100'000];

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val[i].first >> val[i].second;
    }
    //빨리 끝나는 순으로 정렬
    sort(val, val + n, [] (auto a, auto b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    });

    int before = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int s, e;
        tie(s, e) = val[i];
        if (s >= before) {
            cnt += 1;
            before = e;
        }
    }
    cout << cnt;
    return 0;
}