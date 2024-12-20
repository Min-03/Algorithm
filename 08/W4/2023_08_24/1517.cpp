#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> a, t;
long long cnt = 0;

void merge(int lStart, int lEnd, int rEnd) {
    int rStart = lEnd + 1, lPos = lStart, rPos = rStart, tPos = lStart;
    while (lPos <= lEnd && rPos <= rEnd) {
        if (a[lPos] <= a[rPos]) {
            t[tPos++] = a[lPos++];
        } else {
            cnt += lEnd - lPos + 1;
            t[tPos++] = a[rPos++];
        }
    }
    while (lPos <= lEnd) {
        t[tPos++] = a[lPos++];
    }
    while (rPos <= rEnd) {
        t[tPos++] = a[rPos++];
    }
    for (int i = rEnd; i >= lStart; i--) {
        a[i] = t[i];
    }
}

void mergeSort(int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
}

int main() {
    FastIO
    int n;
    cin >> n;
    a.resize(n);
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    copy(a.begin(), a.end(), t.begin());
    mergeSort(0, n - 1);
    cout << cnt;
    return 0;
}