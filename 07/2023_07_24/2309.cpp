#include <bits/stdc++.h>

using namespace std;
int heights[9];
int main() {
    int sum = 0;
    for (int i = 0; i < 9; i ++) {
        cin >> heights[i];
        sum += heights[i];
    }

    int removeIndex1;
    int removeIndex2;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (heights[i] + heights[j] == sum - 100) {
                removeIndex1 = i;
                removeIndex2 = j;
            }
        }
    }
    vector<int> target;
    for (int i = 0; i < 9; i++) {
        if (i != removeIndex1 && i != removeIndex2) {
            target.push_back(heights[i]);
        }
    }

    sort(target.begin(), target.end());
    for (int height : target) {
        cout << height << '\n';
    }
}