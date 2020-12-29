#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int map[54][54];
int visit[54][54];
queue<pair<int, int>> q;

void bfs(void) {
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if(map[nextY][nextX]==1 && visit[nextY][nextX]==0) {
                visit[nextY][nextX]=1;
                q.push(make_pair(nextY, nextX));
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int m, n, k;    // 가로, 세로, 배추의 개수
        cin >> m >> n >> k;

        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));

        for(int j=0; j<k; j++) {
            int x, y;
            scanf("%d%d", &x, &y);
            map[y+1][x+1] = 1;
        }

        int result = 0;
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=m; k++) {
                if(map[j][k]==1 && visit[j][k]==0) {
                    q.push(make_pair(j, k));
                    result++;
                    bfs();
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}