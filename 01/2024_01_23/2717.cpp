#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int pos[1'000'001];
int scores[100'000];

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> nums(n);
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= nums[i]; j++) {
            if (nums[i] % j == 0) {
                if (pos[j] != -1) {
                    scores[pos[j]]++;
                    scores[i]--;
                }
                if (j * j != nums[i] && pos[nums[i] / j] != -1) {
                    scores[pos[nums[i] / j]]++;
                    scores[i]--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) cout << scores[i] << ' ';
    return 0;
}