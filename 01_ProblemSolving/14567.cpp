#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    vector<int> v[1004];
    queue<pair<int, int> > q;
    int indegree[1004];

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        indegree[b]++;
        v[a].push_back(b);
    }

    for(int i=1; i<=n; i++) {
        if(!indegree[i]) q.push({i,1});
    }

    int res[1004];
    while(!q.empty()) {
        int node = q.front().first;
        int seme = q.front().second;
        q.pop();

        res[node] = seme;

        for(int i=0; i<v[node].size(); i++) {
            indegree[v[node][i]]--;
            if(!indegree[v[node][i]]) q.push({v[node][i], max(res[v[node][i]], seme+1)});   
        }
    }

    for(int i=1; i<=n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}