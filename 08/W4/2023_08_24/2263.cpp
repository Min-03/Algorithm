#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct Node {
    int left = -1, right = -1, parent = -1;
};

Node nodes[100'001];
vector<int> in, pos;

void connect(int parent, int child, bool left) {
    nodes[child].parent = parent;
    if (left) {
        nodes[parent].left = child;
    } else {
        nodes[parent].right = child;
    }
}

void go(int inStart, int posStart, int size) {
    int before = -1; //inorder의 이전 기록
    int nextIn = -1, nextPos = -1, nextSize = 0;
    bool ok = true;
    for (int i = inStart, j = posStart; i < inStart + size; i++, j++) {
        if (!ok) {
            nextSize += 1;
            if (before == pos[j]) {
                connect(pos[j], pos[j - 1], false);
                if (nextSize != 1) go(nextIn, nextPos, nextSize);
                ok = true;
                nextSize = 0;
            }
            continue;
        }
        if (in[i] == pos[j]) {
            if (before != -1) {
                connect(in[i], before, true);
            }
            before = in[i];
        } else {
            nextIn = i + 1;
            nextPos = j;
            if (before != -1) {
                connect(in[i], before, true);
            }
            before = in[i];
            ok = false;
        }
    }
}

void preOrder(int curr) {
    if (curr == -1) return;
    cout << curr << ' ';
    preOrder(nodes[curr].left);
    preOrder(nodes[curr].right);
}

int main() {
    FastIO
    int n;
    cin >> n;
    in.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    go(0, 0, in.size());
    int root = 1;
    while (nodes[root].parent != -1) {
        root = nodes[root].parent;
    }
    preOrder(root);
    return 0;
}