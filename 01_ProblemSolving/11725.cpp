#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int parent[100001]; // 부모 노드

void dfs(int x) {
    visited[x] = true;

    for(int i=0; i<v[x].size(); i++) {
        int new_node = v[x][i];
        if(visited[new_node]==false) {
            parent[new_node] = x;
            dfs(new_node);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for(int i=2; i<=n; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}