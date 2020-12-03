#include <iostream>
#include <queue>

using namespace std;

int people, p1, p2;
int map[101][101]={0,};
int visited[101]={0,};
int depth[101]={0,};
queue<int> q;

int bfs(int v) {
    q.push(v);
    visited[v] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(node==p2) return depth[p2];

        for(int i=1; i<=people; i++) {
            if(map[node][i]==1 && visited[i]==0) {
                visited[i] = 1;
                depth[i] = depth[node] + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int main() {
    int n, node1, node2;
    cin >> people >> p1 >> p2 >> n;
    for(int i=0; i<n; i++) {
        cin >> node1 >> node2;
        map[node1][node2] = 1;
        map[node2][node1] = 1;
    }

    cout << bfs(p1);
    return 0;
}