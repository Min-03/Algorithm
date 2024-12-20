#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int heights[100'000];

long long getMidSize(int start, int end) {
    int mid = (start + end) / 2, left = mid, right = mid;
    long long ret = heights[mid], height = heights[mid];
    while (start < left && right < end) {
        if (heights[left - 1] > heights[right + 1]) {
            left--;
            height = min(height, (long long) heights[left]);
        } else {
            right++;
            height = min(height, (long long) heights[right]);
        }
        ret = max(ret, height * (right - left + 1));
    }
    while (start < left) {
        height = min(height, (long long) heights[left]);
        ret = max(ret, height * (end - left + 1));
        left--;
    }
    while (right < end) {
        height = min(height, (long long) heights[right]);
        ret = max(ret, height * (right - start + 1));
        right++;
    }
    height = min({height, (long long) heights[start], (long long) heights[end]});
    ret = max(ret, (end - start + 1) * height);
    return ret;
}

long long size(int start, int end) {
    if (start > end) return 0;
    else if (start == end) return heights[start];

    int mid = (start + end) / 2;
    long long left = size(start, mid);
    long long right = size(mid + 1, end);
    long long midSize = getMidSize(start, end);
    return max({left, right, midSize});
}

int main() {
    FastIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << size(0, n - 1);
    return 0;
}