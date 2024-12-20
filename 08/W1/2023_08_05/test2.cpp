#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    FastIO
    int arr[3][2] = {{1, 2},
                     {3, 4},
                     {5, 6}};
    int temp[3][2];
    memcpy(temp, arr, sizeof(arr));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) cout << temp[i][j] << " \n"[j == 1];
    }
    return 0;
}