#include <bits/stdc++.h>
using namespace std;

string strs[10];
int val[26];
bool check[26];
int nums[10];
vector<char> used;

void setVal() {
    int index = 0;
    for (char ch : used) {
        val[ch - 'A'] = nums[index++];
    }
}

int getNum(string str) {
    int res = 0;
    int length = str.length();
    for (int i = 0; i < length; i++) {
        char ch = str[i];
        res = res * 10 + val[ch - 'A'];
    }
    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        int length = strs[i].length();
        for (int j = 0; j < length; j++) {
            char ch = strs[i][j];
            check[ch - 'A'] = true;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (check[i]) {
            used.push_back((char) (i + 'A'));
        }
    }
    for (int i = 0; i < 10; i++) {
        nums[i] = i;
    }

    int ans = 0;
    do {
        int num = 0;
        //각 문자에 값 할당
        setVal();
        for (int i = 0; i < n; i++) {
            num += getNum(strs[i]);
        }
        ans = max(ans, num);
    } while (next_permutation(nums, nums + 10));
    cout << ans;
    return 0;
}