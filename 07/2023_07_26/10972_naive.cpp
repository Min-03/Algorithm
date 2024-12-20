#include <bits/stdc++.h>
using namespace std;
bool next_perm(vector<int> &vec) {
    int i = vec.size() - 1;
    while (i > 0 && vec.at(i - 1) >= vec.at(i)) i--;
    if (i <= 0) return false;
    int j = vec.size() - 1;
    while (vec.at(j) <= vec.at(i - 1)) j--;
    swap(vec.at(i - 1), vec.at(j));
    stack<int> stack;
    for (int index = i; index < vec.size(); index++) {
        stack.push(vec.at(index));
    }
    for (int index = i; index < vec.size(); index++) {
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
    if (next_perm(vec)) {
        for (int i = 0; i < n; i++) {
            cout << vec.at(i) << " ";
        }
    } else {
        cout << -1;
    }
}