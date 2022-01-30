#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, m;
    int a, b, c;
    int res = 0;
    int visited[1004] = {0,};
    vector<pii> v[1004];
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    pq.push({0, 1});

    while(!pq.empty()) {
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(visited[x]==1) continue;

        visited[x] = 1;
        res += w;

        for(int i=0; i<v[x].size(); i++) {
            int nx = v[x][i].first;
            int nw = v[x][i].second;
            pq.push({nw, nx});
        } 
    }

    cout << res;
    return 0;
}