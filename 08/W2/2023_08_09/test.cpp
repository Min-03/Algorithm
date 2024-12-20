#include <bits/stdc++.h>
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void printFunc(int (&arr)[3][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " \n"[j == 1];
        }
    }
}

int main() {
    FastIO
    int arr1[][2] = {{1, 2},
                  {3, 4},
                     {5, 6}};
    printFunc(arr1);
    return 0;
}