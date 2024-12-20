#include <bits/stdc++.h>
using namespace std;
bool opened[12];
bool visited[4][4];
int nums[4][4];
int n, m, sum = 0;
int right(int row, int col) {
    return (m - 1) * row + col;
}
int left(int row, int col) {
    return (m - 1) * row + col - 1;
}
int calSum(int row, int col) {
    vector<int> vec;
    vec.push_back(nums[row][col]);
    visited[row][col] = true;
    //제일 마지막 열
    if (col == m - 1) {
        row += 1;
        while (row <= n - 1 && !opened[left(row, col)]) {
            vec.push_back(nums[row][col]);
            visited[row][col] = true;
            row += 1;
        }
    }
    //오른쪽이 뚫려 있음
    else if (opened[right(row, col)]) {
        vec.push_back(nums[row][col + 1]);
        visited[row][col + 1] = true;
        col += 2;
        while (col <= m - 1 && opened[left(row, col)]) {
            vec.push_back(nums[row][col]);
            visited[row][col] = true;
            col += 1;
        }
    }
    //오른쪽이 뚤려 있지 않음
    else {
        //제일 처음 열(오른쪽만 확인)
        if (col == 0) {
            row += 1;
            while (row <= n - 1 && !opened[right(row, col)]) {
                vec.push_back(nums[row][col]);
                visited[row][col] = true;
                row += 1;
            }
        }
        //제일 처음 열X(왼쪽, 오른쪽 둘 다 확인)
        else {
            row += 1;
            while (row <= n - 1 && !opened[left(row, col)] && !opened[right(row, col)]) {
                vec.push_back(nums[row][col]);
                visited[row][col] = true;
                row += 1;
            }
        }
    }
    string numStr;
    for (int num : vec) {
        numStr += num + '0';
    }
    return stoi(numStr);
}

void split(int curr) {
    if (curr == n * (m - 1)) {
        int currSum = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    currSum += calSum(i, j);
                }
            }
        }
        sum = max(sum, currSum);
        return;
    }
    opened[curr] = true;
    split(curr + 1);
    opened[curr] = false;
    split(curr + 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            nums[i][j] = line[j] - '0';
        }
    }
    split(0);
    cout << sum;
    return 0;
}