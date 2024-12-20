#include <bits/stdc++.h>
using namespace std;
long long ans[2];
bool check(long long num1, long long num2) {
    return ans[0] == 0 || (num1 + num2 < ans[0] + ans[1]);
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b;
    cin >> a >> b;
    long long mul = a * b;
    vector<int> candidate;
    for (int i = a; i <= b; i++) {
        if (mul % i == 0) candidate.push_back(i);
    }
    for (int num1: candidate) {
        long long num2 = mul / num1;
        if (gcd(num1, num2) == a && lcm(num1, num2) == b && check(num1, num2)) {
            ans[0] = num1;
            ans[1] = num2;
        }
    }
    cout << ans[0] << ' ' << ans[1];
    return 0;
}