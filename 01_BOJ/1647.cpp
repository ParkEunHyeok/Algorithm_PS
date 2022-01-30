#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, m;
    int res = 0, mx=0;
    vector<pii> a[100004];
    int visited[100004] = {0,};
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y, c;
        cin >> x >> y >> c;

        a[x].push_back({y, c});
        a[y].push_back({x, c});
    }

    pq.push({0, 1});

    // 기존 프림 + 가장 큰 가중치 제거 (마을 두개로 분할)
    while(!pq.empty()) {
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(visited[x]==1) continue;

        visited[x] = 1;
        res += w;
        mx = max(mx, w);

        for(int i=0; i<a[x].size(); i++) {
            int ny = a[x][i].first;
            int nw = a[x][i].second;
            pq.push({nw, ny});
        }
    }

    cout << res - mx;
    return 0;
}