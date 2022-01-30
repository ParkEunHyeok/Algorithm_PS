#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, a, b, res=0;
vector<int> v;
bool visited[10002];

int bfs() {
    queue<pair<int, int> > q;
    q.push({a, 0});
    visited[a] = true;

    while(!q.empty()) {
        int node = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(node==b) return cnt;

        int tmp = node-v[node];
        while(tmp>0) {
            if(!visited[tmp]) {
                q.push({tmp, cnt+1});
                visited[tmp] = true;
            }
            tmp -= v[node];
        }

        tmp = node+v[node];
        while(tmp<=n) {
            if(!visited[tmp]) {
                q.push({tmp, cnt+1});
                visited[tmp] = true;
            }
            tmp += v[node];
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }
    cin >> a >> b;

    cout << bfs();
}