#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(0);
    string numStr;
    for (int num : vec) {
        numStr += num + '0';
    }
    cout << stoi(numStr);
    return 0;
}