#include <iostream>
using namespace std;
#define INF 987654321;

int n, result = INF;
int dist[10][10];
bool visited[10];
int start_node;

void shortestPath(int node, int cnt, int cost) {
    if(cnt==n) {
        if(dist[node][start_node])
            result = min(result, cost+dist[node][start_node]);
        return;
    }

    for(int i=0; i<n; i++) {
        if(dist[node][i] && !visited[i]) {
            visited[i] = true;
            shortestPath(i, cnt+1, cost+dist[node][i]);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dist[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        start_node = i;
        visited[i] = true;
        shortestPath(i, 1, 0);
        visited[i] = false;
    }

    cout << result;
    return 0;
}