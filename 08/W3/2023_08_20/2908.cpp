#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FastIO
    string input1, input2;
    cin >> input1 >> input2;
    reverse(input1.begin(), input1.end());
    reverse(input2.begin(), input2.end());
    int num1 = stoi(input1);
    int num2 = stoi(input2);
    cout << (num1 > num2 ? num1 : num2);
    return 0;
}