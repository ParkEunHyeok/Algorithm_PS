#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    vector<int> v[502], indegree, time, res;
    queue<int> q;

    cin >> n;
    indegree.resize(n+1);
    time.resize(n+1);
    res.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a;
        time[i] = a;

        while(1) {
            cin >> b;
            if(b==-1) break;
            indegree[i]++;
            v[b].push_back(i);
        }
    }

    for(int i=1; i<=n; i++) {
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++) {
            indegree[v[node][i]]--;
            res[v[node][i]] = max(res[v[node][i]], res[node]+time[node]);
            if(!indegree[v[node][i]]) q.push(v[node][i]);
        }
    }

    for(int i=1; i<=n; i++) {
        cout << res[i] + time[i] << "\n";
    }
    return 0;
}