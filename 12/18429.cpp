#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int weights[8], orders[8];
int n, k;

bool valid() {
    int weight = 500;
    for (int i = 0; i < n; i++) {
        weight += weights[orders[i]];
        weight -= k;
        if (weight < 500) return false;
    }
    return true;
}

int go(int curr) {
    if (curr == n) {
        return valid() ? 1 : 0;
    }
    int ret = 0;
    for (int i = curr; i < n; i++) {
        swap(orders[i], orders[curr]);
        ret += go(curr + 1);
        swap(orders[i], orders[curr]);
    }
    return ret;
}

int main() {
    FASTIO
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        orders[i] = i;
    }
    cout << go(0);
    return 0;
}