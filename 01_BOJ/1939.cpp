#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int start, fin;
vector<pair<int, int>> v[100002];
bool visited[100002];

bool bfs(int limit) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur==fin) return true;

        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i].first;
            int cost = v[cur][i].second;

            if(!visited[next] && cost>=limit) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    int mx = 0;

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        mx = max(mx, c);
    }
    cin >> start >> fin;

    int low = 0, high = mx;
    while(low<=high) {
        memset(visited, 0, sizeof(visited));
        int mid = (low+high)/2;
        if(bfs(mid)) low = mid+1;
        else high = mid-1;
    }

    cout << high;
    return 0;
}