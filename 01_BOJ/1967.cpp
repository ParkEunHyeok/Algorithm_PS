#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<pair<int, int> > tree[10002];
bool visited[10002];
int ee, res=0;

void dfs(int node, int cost) {
    if(visited[node]) return;

    visited[node] = true;
    if(res < cost) {
        res = cost;
        ee = node;
    }

    for(int i=0; i<tree[node].size(); i++) {
        dfs(tree[node][i].first, cost+tree[node][i].second);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c;

    cin >> n;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    dfs(1,0);
    res = 0;
    memset(visited, 0, sizeof(visited));
    
    dfs(ee, 0);
    cout << res;
    return 0;
}