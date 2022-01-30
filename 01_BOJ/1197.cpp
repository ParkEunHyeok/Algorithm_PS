#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int v, e;
    int res = 0;
    vector<pii> a[10002];
    int visited[10002] = {0,};
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }

    pq.push({0, 1});

    while(!pq.empty()) {
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(visited[x]==1) continue;

        res += w;
        visited[x] = 1;

        for(int i=0; i<a[x].size(); i++) {
            int ny = a[x][i].first;
            int nw = a[x][i].second;
            pq.push({nw, ny});
        }
    }

    cout << res;
    return 0;
}