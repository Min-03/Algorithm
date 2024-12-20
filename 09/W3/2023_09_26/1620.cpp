#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

string names[100'001];
map<string, int> dicNum;

int main() {
    FastIO
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        names[i] = str;
        dicNum.insert({str, i});
    }
    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (isdigit(input[0])) {
            cout << names[stoi(input)] << "\n";
        } else {
            cout << dicNum[input] << "\n";
        }
    }
    return 0;
}