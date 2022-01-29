#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    vector<pair<int, int> > v[1004];
    queue<int> q;
    int indegree[1004] = {0,};
    int dp[1004] = {0,};
    int path[1004] = {0,};
    bool flag = false;

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        indegree[b]++;
        v[a].push_back({b, c});
    }

    q.push(1);
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x==1) {
            if(flag) continue;
            flag = true;
        }

        for(int i=0; i<v[x].size(); i++) {
            int next = v[x][i].first;
            int cost = v[x][i].second;

            if(dp[next] < dp[x] + cost) {
                dp[next] = dp[x] + cost;
                path[next] = x;
            }
            
            indegree[next]--;
            if(!indegree[next]) q.push(next);
        }
    }

    stack<int> s;
    cout << dp[1] << "\n";
    s.push(1);
    int idx = 1;
    while(1) {
        if(path[idx]==1) {
            s.push(1);
            break;
        }
        s.push(path[idx]);
        idx = path[idx];
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}