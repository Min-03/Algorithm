#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

pair<int, int> a[500'000], t[500'000];
int cnts[500'000]; //i번째로 입력받은 수의 등수

void merge(int lStart, int lEnd, int rEnd) {
    int lPos, rPos, tPos, rStart = lEnd + 1;
    lPos = tPos = lStart;
    rPos = rStart;
    while (lPos <= lEnd && rPos <= rEnd) {
        if (a[lPos].first >= a[rPos].first) {
            t[tPos++] = a[lPos++];
        } else {
            cnts[a[rPos].second] -= lEnd - lPos + 1;
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
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        cnts[i] = i + 1;
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << cnts[i] << '\n';
    }
    return 0;
}