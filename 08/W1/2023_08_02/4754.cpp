#include <bits/stdc++.h>
using namespace std;

int graph[9][9];
bool rowUsed[9][10];
bool colUsed[9][10];
bool sqUsed[3][3][10];
bool pairUsed[10][10];
int dx[] = {1, 0};
int dy[] = {0, 1};
int puzNum = 0;
bool found = false;

pair<int, int> convert(string str) {
    return make_pair(str[0] - 'A', (str[1] - '0') - 1);
}

bool validPos(int x, int y) {
    return 0 <= x && x < 9 && 0 <= y && y < 9 && graph[x][y] == 0;
}

void setUsed(int x, int y, int num, bool used) {
    rowUsed[x][num] = colUsed[y][num] = sqUsed[(x / 3)][(y / 3)][num] = used;
    if (used) {
        graph[x][y] = num;
    } else {
        graph[x][y] = 0;
    }
}

bool check(int x, int y, int num) {
    return !rowUsed[x][num] && !colUsed[y][num] && !sqUsed[(x / 3)][(y / 3)][num];
}

void go(int curr) {
    if (found) return;
    if (curr == 81) {
        found = true;
        cout << "Puzzle " << puzNum << '\n';
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << graph[i][j];
            }
            cout << '\n';
        }
        return;
    }
    int x = curr / 9;
    int y = curr % 9;
    if (graph[x][y] != 0) {
        go(curr + 1);
    } else {
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!validPos(nx, ny)) continue;
            for (int j = 1; j <= 9; j++) {
                if (!check(x, y, j)) continue;
                for (int k = 1; k <= 9; k++) {
                    if (j == k || !check(nx, ny, k) || pairUsed[j][k]) continue;
                    setUsed(x, y, j, true);
                    setUsed(nx, ny, k, true);
                    pairUsed[j][k] = pairUsed[k][j] = true;
                    go(curr + 1);
                    setUsed(x, y, j, false);
                    setUsed(nx, ny, k, false);
                    pairUsed[j][k] = pairUsed[k][j] = false;
                }
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        puzNum += 1;
        found = false;
        memset(graph, 0, sizeof(graph));
        memset(colUsed, 0, sizeof(colUsed));
        memset(rowUsed, 0, sizeof(rowUsed));
        memset(sqUsed, 0, sizeof(sqUsed));
        memset(pairUsed, 0, sizeof(pairUsed));
        for (int i = 0; i < n; i++) {
            int u, v, x, y;
            string lu, lv;
            cin >> u >> lu >> v >> lv;
            tie(x, y) = convert(lu);
            setUsed(x, y, u, true);
            tie(x, y) = convert(lv);
            setUsed(x, y, v, true);
            pairUsed[u][v] = pairUsed[v][u] = true;
        }
        for (int i = 1; i <= 9; i++) {
            int x, y;
            string str;
            cin >> str;
            tie(x, y) = convert(str);
            setUsed(x, y, i, true);
        }

        go(0);
    }
    return 0;
}
