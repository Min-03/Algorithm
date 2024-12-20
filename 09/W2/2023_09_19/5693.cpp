#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> inorder, preorder;
int inPos[1'000'001];

void printPost(int preS, int preE, int inS, int inE) {
    if (preS > preE || inS > inE) return;
    int rootIdx = inPos[preorder[preS]];
    int leftSize = rootIdx - inS;
    printPost(preS + 1, preS + leftSize, inS, rootIdx - 1);
    printPost(preS + leftSize + 1, preE, rootIdx + 1, inE);
    cout << preorder[preS] << '\n';
}

int main() {
    FastIO
    int num;
//    freopen("input.txt", "r", stdin);
    while (cin >> num) {
        preorder.push_back(num);
        inorder.push_back(num);
    }
    sort(inorder.begin(), inorder.end());
    int n = preorder.size();

    for (int i = 0; i < n; i++) {
        inPos[inorder[i]] = i;
    }

    printPost(0, n - 1, 0, n - 1);
    return 0;
}