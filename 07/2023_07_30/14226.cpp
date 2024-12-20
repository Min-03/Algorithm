#include <bits/stdc++.h>
using namespace std;

int visited[1001][1001]; //visited[스크린][클립보드]
int s;

int bfs() {
    queue<pair<int, int>> q;
    visited[1][0] = 0;
    q.emplace(1, 0);
    while (!q.empty()) {
        int screen = q.front().first;
        int clip = q.front().second;
        q.pop();
        if (screen == s) {
            return visited[screen][clip];
        }
        if (screen - 1 >= 0 && (visited[screen - 1][clip] == -1 || visited[screen - 1][clip] > visited[screen][clip] + 1)) {
            visited[screen - 1][clip] = visited[screen][clip] + 1;
            q.emplace(screen - 1, clip);
        }
        if (screen + clip <= 1000 && (visited[screen + clip][clip] == -1 || visited[screen + clip][clip] > visited[screen][clip] + 1)) {
            visited[screen + clip][clip] = visited[screen][clip] + 1;
            q.emplace(screen + clip, clip);
        }
        if (visited[screen][screen] == -1 || visited[screen][screen] > visited[screen][clip] + 1) {
            visited[screen][screen] = visited[screen][clip] + 1;
            q.emplace(screen, screen);
        }
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    memset(visited, -1, sizeof(visited));
    cout << bfs();
    return 0;
}
