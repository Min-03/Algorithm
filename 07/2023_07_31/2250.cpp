#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left, right;
};
Node nodes[10'001];
vector<int> levelNode[10'001];
int cols[10'001];
int parent[10'001];
int maxLev = 0;
int col = 0;

void inorder(int curr, int level) {
    if (curr == -1) return;
    inorder(nodes[curr].left, level + 1);
    cols[curr] = ++col;
    levelNode[level].push_back(curr);
    maxLev = max(maxLev, level);
    inorder(nodes[curr].right, level + 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int leaf = -1;
    for (int i = 0; i < n; i++) {
        int curr, left, right;
        cin >> curr >> left >> right;
        if (left != -1) parent[left] = curr;
        nodes[curr].left = left;
        if (right != -1) parent[right] = curr;
        nodes[curr].right = right;
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            root = i;
            break;
        }
    }
    inorder(root, 1);

    int maxWidth = -1;
    int widthLev = -1;
    for (int i = 1; i <= maxLev; i++) {
        int maxCol = cols[*max_element(levelNode[i].begin(), levelNode[i].end(), [] (int x, int y) {
            return cols[x] < cols[y];
        })];
        int minCol = cols[*min_element(levelNode[i].begin(), levelNode[i].end(), [] (int x, int y) {
            return cols[x] < cols[y];
        })];
        int width = maxCol - minCol + 1;
        if (width > maxWidth) {
            maxWidth = width;
            widthLev = i;
        }
    }
    cout << widthLev << ' ' << maxWidth;
    return 0;
}