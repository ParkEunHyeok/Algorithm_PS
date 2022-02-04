#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, c, m, tmp;
    vector<int> v[10002];
    queue<int> q;
    int indegree[10002] = {0,};
    int time[10002] = {0,};
    int w[10002] = {0,};

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> c >> m;
        time[i] = c;
        indegree[i] = m;
        if(m==0) q.push(i);

        for(int j=0; j<m; j++) {
            cin >> tmp;
            v[tmp].push_back(i);
        }
    }

    int res = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        res = max(res, time[cur]+w[cur]);
        
        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i];
            w[next] = max(w[next], w[cur]+time[cur]);
            indegree[next]--;
            if(!indegree[next]) q.push(next);
        }
    }

    cout << res;
    return 0;
}