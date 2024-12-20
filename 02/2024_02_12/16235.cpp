#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct tree {int x, y, age;};

vector<tree> trees, dead, nxt;
int graph[10][10], add[10][10];
int n, m, k;

void spread(int x, int y) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            nxt.push_back({nx, ny, 1});
        }
    }
}

int main() {
    FastIO
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> add[i][j];
            graph[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        trees.push_back({--x, --y, age});
    }
    sort(trees.begin(), trees.end(), [] (auto a, auto b) {
        return a.age > b.age;
    });

    while (k--) {
        dead.clear();
        nxt.clear();
        //나무가 양분을 먹을 수 있으면 자람
        for (int i = trees.size() - 1; i >= 0; i--) {
            auto [x, y, age] = trees[i];
            if (graph[x][y] >= age) {
                graph[x][y] -= age;
                nxt.push_back({x, y, age + 1});
            } else {
                dead.push_back({x, y, age});
            }
        }
        reverse(nxt.begin(), nxt.end());

        //죽은 나무 나이 / 2만큼 양분 추가
        for (auto [x, y, age] : dead) {
            graph[x][y] += age / 2;
        }

        //나무 나이가 5의 배수면 인접 8개 칸에 나무 새로 생성
        int size = nxt.size();
        for (int i = 0; i < size; i++) {
            auto [x, y, age] = nxt[i];
            if (age % 5 == 0) spread(x, y);
        }

        //add[i][j]만큼 양분 추가
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] += add[i][j];
            }
        }
        trees = nxt;
    }
    cout << trees.size();
    return 0;
}