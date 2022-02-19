#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
#define INF 1987654321;

vector<pii> adj[1002];
int d[1002], pre[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, s, e;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    for(int i=0; i<=n; i++) d[i] = INF;
    cin >> s >> e;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if(d[cur.second]!=cur.first) continue;

        for(int i=0; i<adj[cur.second].size(); i++) {
            int next = adj[cur.second][i].second;
            int cost = adj[cur.second][i].first;
            if(d[next] <= d[cur.second]+cost) continue;
            d[next] = d[cur.second]+cost;
            pq.push({d[next], next});
            pre[next] = cur.second;
        }
    }

    stack<int> st;
    int node = e;
    while(1) {
        st.push(node);
        if(node==s) break;
        node = pre[node];
    }

    cout << d[e] << "\n" << st.size() << "\n";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}