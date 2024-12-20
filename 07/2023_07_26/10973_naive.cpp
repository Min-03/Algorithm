#include <bits/stdc++.h>
using namespace std;
bool prev_perm(vector<int> &vec) {
    int n = vec.size();
    int i = n - 1;
    while (i > 0 && vec.at(i - 1) <= vec.at(i)) i--;
    if (i <= 0) return false;
    int j = n - 1;
    while (vec.at(i - 1) <= vec.at(j)) j--;
    swap(vec.at(i - 1), vec.at(j));
    stack<int> stack;
    for (int index = i; index < n; index++) {
        stack.push(vec.at(index));
    }
    for (int index = i; index < n; index++) {
        vec.at(index) = stack.top();
        stack.pop();
    }
    return true;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    if (prev_perm(vec)) {
        for (int i = 0; i < n; i++) {
            cout << vec.at(i) << ' ';
        }
    } else {
        cout << -1;
    }
}
