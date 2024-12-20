#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool banned[500'000];
string nums[500'000];
map<string, int> cnts;

int main() {
    FASTIO
    int k, l;
    cin >> k >> l;
    for (int i = 0; i < l; i++) {
        cin >> nums[i];
        cnts[nums[i]]++;
    }
    for (int i = 0; i < l; i++) {
        if (cnts[nums[i]] > 1) {
            banned[i] = true;
            cnts[nums[i]]--;
        }
    }
    for (int i = 0; i < l && k > 0; i++) {
        if (banned[i]) continue;
        cout << nums[i] << '\n';
        k--;
    }
    return 0;
}