#include <iostream>
#include <vector>
using namespace std;

int n, rem;
vector<int> map[50];
bool visited[52];
int ans=0;

void dfs(int v) {
    visited[v] = true;

    for(int i=0; i<map[v].size(); i++) {
        if(map[v].size()==1 && map[v][i]==rem) {
            ans++;
            break;
        }

        if(!visited[map[v][i]]) {
            dfs(map[v][i]);
        }
    }

    if(map[v].size()==0) {
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int node;
        cin >> node;

        if(node==-1) continue;
        map[node].push_back(i);
    }
    cin >> rem;

    dfs(rem);
    ans = 0;

    for(int i=0; i<n; i++) {
        if(!visited[i]) dfs(i);
    }

    cout << ans;
    return 0;
}   