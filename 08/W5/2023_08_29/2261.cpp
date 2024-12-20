#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int, int>> points;

int calDist(int a, int b) {
    int xDiff = points[a].first - points[b].first;
    int yDiff = points[a].second - points[b].second;
    return xDiff * xDiff + yDiff * yDiff;
}

int calMidDist(int start, int end, int limit) {
    int mid = (start + end) / 2;
    int midX = points[mid].first;
    vector<pair<int, int>> candidates; // y, x 순서
    candidates.reserve(end - start + 1);
    for (int i = start; i <= end; i++) {
        auto [currX, currY] = points[i];
        int diff = abs(currX - midX);
        if (diff * diff < limit) {
            candidates.emplace_back(currY, currX);
        }
    }
    sort(candidates.begin(), candidates.end());
    int ret = 1e9;
    for (int i = 0; i < candidates.size(); i++) {
        auto [y, x] = candidates[i];
        for (int j = i + 1; j < candidates.size(); j++) {
            auto [yy, xx] = candidates[j];
            int yDiff = yy - y;
            if (yDiff * yDiff >= limit) break;
            int xDiff = xx - x;
            int dist = xDiff * xDiff + yDiff * yDiff;
            ret = min(ret, dist);
        }
    }
    return ret;
}

int getMinDist(int start, int end) {
    if (start + 1 == end) {
        return calDist(start, end);
    } else if (start + 2 == end) {
        return min({calDist(start, end), calDist(start + 1, end), calDist(start, start + 1)});
    }

    int mid = (start + end) / 2;
    int left = getMinDist(start, mid);
    int right = getMinDist(mid + 1, end);
    int midDist = calMidDist(start, end, min(left, right));
    return min({left, right, midDist});
}

int main() {
    FastIO
    int n;
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    cout << getMinDist(0, n - 1);
    return 0;
}