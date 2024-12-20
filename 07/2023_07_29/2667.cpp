#include <bits/stdc++.h>
using namespace std;
int graph[25][25];
bool visited[25][25];
int n, cnt = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int row, int col) {
    visited[row][col] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (0 <= newRow && newRow < n && 0 <= newCol && newCol < n && !visited[newRow][newCol] && graph[newRow][newCol] == 1) {
            dfs(newRow, newCol);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string numStr;
        cin >> numStr;
        for (int j = 0; j < n; j++) {
            graph[i][j] = numStr[j] - '0';
        }
    }
    vector<int> houses;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                houses.push_back(cnt);
            }
        }
    }
    sort(houses.begin(), houses.end());
    cout << houses.size() << '\n';
    for (int house : houses) {
        cout << house << '\n';
    }
    return 0;
}