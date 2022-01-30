#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001] = {0,};
int visit[1001] = {0,};
queue<int> q;
int n, m, v;
int result = 0;

void bfs(int v) {
    q.push(v);
    visit[v] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i=0; i<=n; i++) {
            if(map[node][i]==1 && visit[i]==0) {
                visit[i] = 1;
                q.push(i);
            }
        }
    }
    result++;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        map[num1][num2] = 1;
        map[num2][num1] = 1;
    }

    for(int i=1; i<=n; i++) {
        if(visit[i]==0) {
            bfs(i);
        }
    }

    printf("%d", result);
    return 0;
}