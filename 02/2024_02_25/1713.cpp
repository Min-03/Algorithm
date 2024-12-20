#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> candidates;
int cnts[101];

int main() {
    FastIO
    int n, tc;
    cin >> n >> tc;
    while (tc--) {
        int num;
        cin >> num;
        if (find(candidates.begin(), candidates.end(), num) != candidates.end()) {
            cnts[num]++;
            continue;
        }
        if (candidates.size() < n) {
            candidates.push_back(num);
            cnts[num] = 1;
            continue;
        }
        int loCnt = 1e6, loIdx;
        for (int i = 0; i < candidates.size(); i++) {
            if (cnts[candidates[i]] < loCnt) {
                loIdx = i;
                loCnt = cnts[candidates[i]];
            }
        }
        cnts[candidates[loIdx]] = 0;
        candidates.erase(candidates.begin() + loIdx);
        candidates.push_back(num);
        cnts[num] = 1;
    }
    sort(candidates.begin(), candidates.end());
    for (int candidate : candidates) {
        cout << candidate << ' ';
    }
    return 0;
}