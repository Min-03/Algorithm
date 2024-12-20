#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<int, int> orders;
int b[500'000], t[500'000];
long long cnt = 0;

void merge(int l, int mid, int r) {
    int lp = l, lEnd = mid, rp = mid + 1, rEnd = r;
    int tp = lp;
    while (lp <= lEnd && rp <= rEnd) {
        if (b[lp] <= b[rp]) {
            t[tp++] = b[lp++];
        } else {
            t[tp++] = b[rp++];
            cnt += lEnd - lp + 1;
        }
    }
    while (lp <= lEnd) t[tp++] = b[lp++];
    while (rp <= rEnd) t[tp++] = b[rp++];
    for (int i = l; i <= r; i++) b[i] = t[i];
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        orders[num] = i;
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        b[i] = orders[num];
    }
    merge_sort(0, n - 1);
    cout << cnt;
    return 0;
}