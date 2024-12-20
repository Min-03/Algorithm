#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> numsA, numsB, sumsA, sumsB;

int main() {
    FastIO
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n / 2; i++) {
        int num;
        cin >> num;
        numsA.push_back(num);
    }
    for (int i = n / 2; i < n; i++) {
        int num;
        cin >> num;
        numsB.push_back(num);
    }
    sumsA.reserve(1 << 20);
    sumsB.reserve(1 << 20);
    int sizeA = numsA.size(), sizeB = numsB.size();
    for (int set = 1; set < (1 << sizeA); set++) {
        int sum = 0;
        for (int i = 0; i < sizeA; i++) {
            if (set & (1 << i)) sum += numsA[i];
        }
        sumsA.push_back(sum);
    }
    for (int set = 1; set < (1 << sizeB); set++) {
        int sum = 0;
        for (int i = 0; i < sizeB; i++) {
            if (set & (1 << i)) sum += numsB[i];
        }
        sumsB.push_back(sum);
    }
    sort(sumsB.begin(), sumsB.end());
    long long ans = 0;
    for (int sum : sumsA) {
        if (sum == s) ans++;
    }
    for (int sum : sumsB) {
        if (sum == s) ans++;
    }
    for (int sum : sumsA) {
        int cnt = upper_bound(sumsB.begin(), sumsB.end(), s - sum) - lower_bound(sumsB.begin(), sumsB.end(), s - sum);
        ans += cnt;
    }
    cout << ans;
    return 0;
}