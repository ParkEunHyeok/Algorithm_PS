#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    vector<pair<int, int>> v[102];
    vector<int> ans;
    queue<int> q;
    int indegree[102] = {0,};
    int cnt[102] = {0,};

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        indegree[b]++;
    }

    q.push(n);
    cnt[n] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(v[cur].empty()) ans.push_back(cur);

        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i].first;
            int cost = v[cur][i].second;

            cnt[next] += cnt[cur] * cost;
            indegree[next]--;
            if(!indegree[next]) q.push(next);
        }
    }
    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " " << cnt[ans[i]] << "\n";
    }
    return 0;
}