#include <bits/stdc++.h>
using namespace std;
void printArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << '\n';
    }
}
void printArr2(const int arr[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << '\n';
        }
    }
}
void printVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << '\n';
    }
}
void printVec2(vector<vector<int>> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << '\n';
        }
    }
    vec[0][0] = 8;
}
int main() {
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> vec;
    vector<int> vec1;
    vector<int> vec2;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec.push_back(vec1);
    vec.push_back(vec2);
    cout << "printVec2\n";
    printVec2(vec);
    cout << "main\n";
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << '\n';
        }
    }
    cout << "forEach\n";
    for (vector<int> subVec : vec) {
        for (int num : subVec) {
            cout << num << '\n';
        }
    }
}