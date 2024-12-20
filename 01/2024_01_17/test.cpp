#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void test(int arr[3]) {
    arr[2] = 1;
}

void test(vector<int> vec) {
    vec[2] = 1;
}

void test2(vector<int> &vec) {
    vec[2] = 1;
}

int main() {
    FastIO
    int arr[] = {2, 2, 2};
    vector<int> vec = {2, 2, 2};
    test(arr);
    test(vec);
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
    for (int num : vec) {
        cout << num << ' ';
    }
    test2(vec);
    cout << '\n';
    for (int num : vec) {
        cout << num << ' ';
    }
    return 0;
}