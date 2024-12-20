#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<int> likes[401];
int graph[20][20];
int students[400];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

pair<int, int> getPos(int target) {
    int retX, retY, hiLikes = -1, hiEmpties = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) continue;
            int emptyNum = 0, likeNum = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (graph[nx][ny] == 0) emptyNum++;
                else if (find(likes[target].begin(), likes[target].end(), graph[nx][ny])
                    != likes[target].end()) likeNum++;
            }
            if (hiLikes > likeNum) continue;
            if (hiLikes == likeNum && hiEmpties >= emptyNum) continue;
            hiLikes = likeNum;
            hiEmpties = emptyNum;
            retX = i;
            retY = j;
        }
    }
    return {retX, retY};
}

int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        cin >> students[i];
        for (int j = 0; j < 4; j++) {
            int like;
            cin >> like;
            likes[students[i]].push_back(like);
        }
    }
    for (int i = 0; i < n * n; i++) {
        auto [x, y] = getPos(students[i]);
        graph[x][y] = students[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int student = graph[i][j];
            int likeNum = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (find(likes[student].begin(), likes[student].end(), graph[nx][ny])
                    != likes[student].end()) likeNum++;
            }
            ans += (likeNum == 0) ? 0 : pow(10, likeNum - 1);
        }
    }
    cout << ans;
    return 0;
}