#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    vector<int> v[32002];
    int indegree[32002];
    priority_queue<int, vector<int>, greater<int> > q;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        v[a].push_back(b);
    }

    for(int i=1; i<=n; i++) {
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty()) {
        int tmp = q.top();
        q.pop();

        cout << tmp << " ";

        for(int i=0; i<v[tmp].size(); i++) {
            indegree[v[tmp][i]]--;
            if(!indegree[v[tmp][i]]) q.push(v[tmp][i]);
        }
    }

    return 0;
}