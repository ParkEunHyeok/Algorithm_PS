#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    vector<int> v[1004];
    vector<int> answer;
    queue<int> q;
    int indegree[1004];
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int k, prev, cur;
        
        cin >> k;
        cin >> prev;

        for(int j=1; j<k; j++) {
            cin >> cur;
            indegree[cur]++;
            v[prev].push_back(cur);
            prev = cur;
        } 
    }

    for(int i=1; i<=n; i++) {
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty()) {
        int tmp = q.front();
        q.pop();

        answer.push_back(tmp);

        for(int i=0; i<v[tmp].size(); i++) {
            int next = v[tmp][i];
            indegree[next]--;
            if(!indegree[next]) q.push(next);
        }
    }

    if(answer.size()!=n) cout << 0;
    else {
        for(int i=0; i<answer.size(); i++) {
            cout << answer[i] << "\n";
        }
    }

    return 0;
}