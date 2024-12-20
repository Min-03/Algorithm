#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int n, l;
    cin >> n >> l;
    vector<int> nums(n);
    priority_queue<int, vector<int>, greater<int>> pq, del;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        pq.push(nums[i]);
        if (i - l >= 0) del.push(nums[i - l]);
        while (!del.empty() && pq.top() == del.top()) {
            pq.pop();
            del.pop();
        }
        cout << pq.top() << ' ';
    }
    return 0;
}