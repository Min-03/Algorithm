#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<char>> vecs;
    int index = 0;
    for (int i = 0; i < n; i++) {
        vector<char> temp;
        for (int j = i; j < n; j++) {
            temp.push_back(str[index++]);
        }
        vecs.push_back(temp);
    }

    return 0;
}