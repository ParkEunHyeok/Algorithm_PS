#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;

    while(t--) {
        int n, k, w;
        int node[1004];
        int indegree[1004] = {0,};
        int time[1004] = {0,};
        vector<int> v[1004];
        queue<int> q;

        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> node[i];
        }
        for(int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            indegree[y]++;
            v[x].push_back(y);
        }
        cin >> w;

        for(int i=1; i<=n; i++) {
            if(!indegree[i]) {
                q.push(i);
                time[i] = node[i];
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int i=0; i<v[cur].size(); i++) {
                int next = v[cur][i];
                time[next] = max(time[next], time[cur]+node[next]);
                
                indegree[next]--;
                if(!indegree[next]) q.push(next);
            }
        }

        cout << time[w] << "\n";
    }

    return 0;
}