#include <bits/stdc++.h>
int costs[10][10];
using namespace std;
int calCost(vector<int> vec) {
    int cost = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        cost += costs[vec.at(i)][vec.at(i + 1)];
        if (costs[vec.at(i)][vec.at(i + 1)] == 0) {
            return -1;
        }
    }
    if (costs[vec.back()][vec.at(0)] == 0) {
        return -1;
    } else {
        cost += costs[vec.back()][vec.at(0)];
    }
    return cost;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec.at(i) = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costs[i][j];
        }
    }
    int total = 1e9;
    do {
        int cost = calCost(vec);
        if (cost != -1) {
            total = min(total, cost);
        }
    } while(next_permutation(vec.begin(), vec.end()));
    cout << total;
    return 0;
}