#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define INF 1987654321

int n, land_cnt=0, res=INF;
int board[102][102];
int map[102][102];
int map2[102][102];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool visited[102][102];
queue<pair<int, int> > Q;

void land(int a, int b) {
    queue<pair<int, int> > q;
    q.push({a, b});
    map[a][b] = land_cnt;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];
            if(nextY<0 || nextY>=n || nextX<0 || nextX>=n) continue;
            if(!visited[nextY][nextX] && board[nextY][nextX]) {
                visited[nextY][nextX] = true;
                map[nextY][nextX] = land_cnt;
                q.push({nextY, nextX});
            }
        }
    }
}

int bridge(int k) {
    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(nextY<0 || nextY>=n || nextX<0 || nextX>=n) continue;
            if(!visited[nextY][nextX] && board[nextY][nextX]==1 && map[nextY][nextX]!=k) {
                return map2[y][x]-1;
            }

            if(!visited[nextY][nextX] && map2[nextY][nextX]==0) {
                visited[nextY][nextX] = true;
                map2[nextY][nextX] = map2[y][x]+1;
                Q.push({nextY, nextX});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && board[i][j]) {
                visited[i][j] = true;
                land_cnt++;
                land(i, j);
            }
        }
    }
    memset(visited, 0, sizeof(visited));

    for(int k=1; k<=land_cnt; k++) {
        while(!Q.empty()) Q.pop();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j]==k) {
                    map2[i][j]=1;
                    Q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        res = min(res, bridge(k));
        memset(visited, 0, sizeof(visited));
        memset(map2, 0, sizeof(map2));
    }

    cout << res;
    return 0;
}