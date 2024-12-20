#include <bits/stdc++.h>
using namespace std;

struct Node{
    int left, right;
};
Node nodes[26];
const int emptyCh = '.' - 'A';

void preOrder(int curr) {
    if (curr == emptyCh) return;
    cout << (char) (curr + 'A');
    preOrder(nodes[curr].left);
    preOrder(nodes[curr].right);
}

void inOrder(int curr) {
    if (curr == emptyCh) return;
    inOrder(nodes[curr].left);
    cout << (char) (curr + 'A');
    inOrder(nodes[curr].right);
}

void postOrder(int curr) {
    if (curr == emptyCh) return;
    postOrder(nodes[curr].left);
    postOrder(nodes[curr].right);
    cout << (char) (curr + 'A');
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        char curr, left, right;
        cin >> curr >> left >> right;
        nodes[curr - 'A'].left = left - 'A';
        nodes[curr - 'A'].right = right - 'A';
    }
    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
    return 0;
}