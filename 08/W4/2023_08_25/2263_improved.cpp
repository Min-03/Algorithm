#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> in, post;
int posOfIn[100'001];

void go(int inS, int inE, int postS, int postE) {
    if (inS > inE || postS > postE) return;
    int root = post[postE];
    int pos = posOfIn[root];
    cout << root << ' ';
    int leftSize = (pos - 1) - inS + 1;
    go(inS, pos - 1, postS, postS + leftSize - 1);
    go(pos + 1, inE, postS + leftSize, postE - 1);
}

int main() {
    FastIO
    int n;
    cin >> n;
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        posOfIn[in[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    go(0, n - 1, 0, n - 1);
    return 0;
}