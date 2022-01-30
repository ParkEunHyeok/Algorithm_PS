#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m, start, ee, res=0;
int indegree[10002];
int time[10002];
bool visited[10002];
vector<pii> v[10002], rv[10002];

void mx_dist(int s) {
    queue<pii> q;
    q.push({s, 0});

    while(!q.empty()) {
        int x = q.front().first;
        int w = q.front().second;
        q.pop();

        for(int i=0; i<v[x].size(); i++) {
            int nx = v[x][i].first;
            int nw = v[x][i].second;

            indegree[nx]--;
            time[nx] = max(time[nx], w + nw);

            if(!indegree[nx]) q.push({nx, time[nx]});
        }
    }
}

void bfs(int e) {
    queue<int> q;
    q.push(e);
    visited[e] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<rv[cur].size(); i++) {
            int prev = rv[cur][i].first;
            int pw = rv[cur][i].second;

            if(time[cur] - pw == time[prev]) {
                res++;
                if(!visited[prev]) {
                    visited[prev] = true;
                    q.push(prev);
                }
            }
        }
    }
}

int main() {
    int a, b, c;
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        indegree[b]++;
        v[a].push_back({b, c});
        rv[b].push_back({a, c});
    }
    cin >> start >> ee;

    mx_dist(start);
    bfs(ee);

    cout << time[ee] << "\n" << res;

    return 0;
}