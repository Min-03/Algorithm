#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        int n;
        string p, str;
        cin >> p >> n >> str;
        vector<int> nums;
        nums.reserve(n);
        int curr = 0;
        for (char ch : str) {
            if (isdigit(ch)) {
                curr = curr * 10 + ch - '0';
            } else {
                if (curr != 0) nums.push_back(curr);
                curr = 0;
            }
        }

        int s = 0, e = n - 1;
        bool reversed = false;
        for (char ch : p) {
            if (ch == 'R') {
                reversed ^= 1;
            } else {
                if (reversed) e--;
                else s++;
            }
        }

        //정답 출력
        if (s > e + 1) {
            cout << "error\n";
            continue;
        } else if (s == e + 1) {
            cout << "[]\n";
            continue;
        }
        cout << '[';
        if (reversed) {
            for (int i = e; i > s; i--) {
                cout << nums[i] << ',';
            }
            cout << nums[s] << "]\n";
        } else {
            for (int i = s; i < e; i++) {
                cout << nums[i] << ',';
            }
            cout << nums[e] << "]\n";
        }
    }
    return 0;
}