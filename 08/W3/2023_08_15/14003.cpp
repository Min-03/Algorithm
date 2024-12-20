#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int before[1'000'001];
int nums[1'000'001];

int main() {
    FastIO
    int n;
    cin >> n;
    vector<int> lis; //값이 아닌 인덱스를 저장
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        nums[i] = num;
        auto iter = lower_bound(lis.begin(), lis.end(), i, [] (int a, int b) {
            return nums[a] < nums[b];
        });
        if (iter == lis.end()) {
            if (!lis.empty()) before[i] = lis.back();
            lis.push_back(i);
        } else {
            if (iter != lis.begin()) before[i] = *(iter - 1);
            *iter = i;
        }
    }
    cout << lis.size() << '\n';
    int curr = lis.back();
    stack<int> s;
    while (before[curr] != 0) {
        s.push(nums[curr]);
        curr = before[curr];
    }
    s.push(nums[curr]);
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}