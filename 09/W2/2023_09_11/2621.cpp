#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<char> colors(5);
vector<int> nums(5);

pair<int, char> cntSameColor() {
    int ret = 1, cnt = 1, retColor = colors[0];
    for (int i = 1; i < 5; i++) {
        if (colors[i] == colors[i - 1]) cnt++;
        else {
            if (ret < cnt) {
                ret = cnt;
                retColor = colors[i - 1];
            }
            cnt = 1;
        }
    }
    if (ret < cnt) {
        ret = cnt;
        retColor = colors[4];
    }
    return {ret, retColor};
}

pair<int, int> cntSameNum() {
    int ret = 1, cnt = 1, retNum = nums[0];
    for (int i = 1; i < 5; i++) {
        if (nums[i] == nums[i - 1]) cnt++;
        else {
            if (ret < cnt) {
                ret = cnt;
                retNum = nums[i - 1];
            }
            cnt = 1;
        }
    }
    if (ret < cnt) {
        ret = cnt;
        retNum = nums[4];
    }
    return {ret, retNum};
}

int main() {
    FastIO
    for (int i = 0; i < 5; i++) {
        cin >> colors[i] >> nums[i];
    }
    sort(colors.begin(), colors.end());
    sort(nums.begin(), nums.end());
    int ans = 0;
    auto [sameNum, num] = cntSameNum();
    auto [sameColor, color] = cntSameColor();
    bool conti = true;
    for (int i = 1; i < 5; i++) {
        if (nums[i - 1] != nums[i] - 1) {
            conti = false;
        }
    }
    if (sameColor == 5) {
        //1
        if (conti) ans = max(ans, nums[4] + 900);
        //4
        else ans = max(ans, nums[4] + 600);
    }
    if (sameNum == 4) {
        //2
        ans = max(ans, num + 800);
    }
    if (sameNum == 3) {
        vector<int> others;
        for (int i = 0; i < 5; i++) {
            if (nums[i] != num) others.push_back(nums[i]);
        }
        //3
        if (others[0] == others[1]) ans = max(ans, num * 10 + others[0] + 700);
        //6
        else ans = max(ans, num + 400);
    }
    //5
    if (conti) ans = max(ans, nums[4] + 500);
    if (sameNum == 2) {
        vector<int> others;
        for (int i = 0; i < 5; i++) {
            if (nums[i] != num) others.push_back(nums[i]);
        }
        //7
        if (others[0] == others[1] || others[1] == others[2]) {
            ans = max(ans, max(num, others[1]) * 10 + min(num, others[1]) + 300);
        }
        //8
        else {
            ans = max(ans, num + 200);
        }
    }
    //9
    ans = max(ans, nums[4] + 100);
    cout << ans;
    return 0;
}