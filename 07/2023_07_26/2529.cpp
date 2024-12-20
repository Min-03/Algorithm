#include <bits/stdc++.h>
using namespace std;
int k;
vector<char> charVec;
bool valid(vector<int> vec) {
    for (int i = 0; i < k; i++) {
        char ch = charVec.at(i);
        if (ch == '<' && vec.at(i) > vec.at(i + 1)) {
            return false;
        } else if (ch == '>' && vec.at(i) < vec.at(i + 1)) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> vec(10);
    for (int i = 0; i < 10; i++) {
        vec.at(i) = i;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        char ch;
        cin >> ch;
        charVec.push_back(ch);
        cin.ignore();
    }
    long long low = 1e11;
    string lowStr;
    long long high = 0;
    string highStr;
    do {
        if (!valid(vec)) continue;
        string numStr;
        for (int i = 0; i < k + 1; i++) {
            numStr += vec.at(i) + '0';
        }
        long long num = stoll(numStr);
        if (low > num) {
            low = num;
            lowStr = numStr;
        }
        if (high < num) {
            high = num;
            highStr = numStr;
        }
    } while(next_permutation(vec.begin(), vec.end()));
    cout << highStr << '\n';
    cout << lowStr << '\n';
    return 0;
}