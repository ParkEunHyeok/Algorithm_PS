#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1004][1004];
int visited[1004][1004][2];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int bfs() {
    queue<pair<pair<int, int>, int> > q;
    q.push({{0,0},1});
    visited[0][0][1] = 1;

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();

        if(y==n-1 && x==m-1) return visited[y][x][block]; 

        for(int i=0; i<4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(0<=nextY && 0<=nextX && nextY<n && nextX<m) {
                if(map[nextY][nextX]==1 && block) {
                    visited[nextY][nextX][block-1] = visited[y][x][block]+1;
                    q.push({{nextY, nextX}, block-1});                     
                }
                else if(map[nextY][nextX]==0 && visited[nextY][nextX][block]==0) {
                    visited[nextY][nextX][block] = visited[y][x][block]+1;
                    q.push({{nextY,nextX},block});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            map[i][j] = str[j]-'0';
        }
    }

    cout << bfs();
    return 0;
}