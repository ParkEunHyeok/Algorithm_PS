#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
typedef pair<ll, int> pii;

const ll INF = (ll)300000*1000000000;
int n, m;
vector<pii> adj[100002];
ll odd[100002], even[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    for(int i=1; i<=n; i++) {
        odd[i] = INF;
        even[i] = INF;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    even[1] = 0;

    while(!pq.empty()) {
        ll cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cost%2==0) {
            if(even[cur]!=cost) continue;
        }
        else {
            if(odd[cur]!=cost) continue;
        }

        for(int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i].second;
            ll nCost = adj[cur][i].first;

            if((cost+nCost)%2==0) {
                if(even[next] <= cost+nCost) continue;
                even[next] = cost + nCost;
                pq.push({even[next], next});
            }
            if((cost+nCost)%2==1) {
                if(odd[next] <= cost+nCost) continue;
                odd[next] = cost + nCost;
                pq.push({odd[next], next});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(odd[i]==INF) cout << -1;
        else cout << odd[i];
        cout << " ";
        if(even[i]==INF) cout << -1;
        else cout << even[i];
        cout << "\n";
    }
    return 0;
}