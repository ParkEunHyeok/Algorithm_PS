#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int r, c;
string map[1002];
int dist1[1002][1002];  // 불
int dist2[1002][1002];  // 지훈
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int, int> > q1, q2;

void fire_bfs() {
    while(!q1.empty()) {
        int curY = q1.front().first;
        int curX = q1.front().second;
        q1.pop();

        for(int i=0; i<4; i++) {
            int ny = curY + dir[i][0];
            int nx = curX + dir[i][1];

            if(nx<0 || ny<0 || ny>=r || nx>=c) continue;
            if(dist1[ny][nx]>=0 || map[ny][nx]=='#') continue;

            dist1[ny][nx] = dist1[curY][curX]+1;
            q1.push({ny, nx});
        }
    }
}

void jihun_bfs() {
    while(!q2.empty()) {
        int curY = q2.front().first;
        int curX = q2.front().second;
        q2.pop();

        for(int i=0; i<4; i++) {
            int ny = curY + dir[i][0];
            int nx = curX + dir[i][1];

            if(nx<0 || ny<0 || ny>=r || nx>=c) {
                cout << dist2[curY][curX]+1;
                return;
            }

            if(dist2[ny][nx]>=0 || map[ny][nx]=='#') continue;
            if(dist1[ny][nx]!=-1 && dist1[ny][nx] <= dist2[curY][curX]+1) continue;
        
            dist2[ny][nx] = dist2[curY][curX]+1;
            q2.push({ny, nx});
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tmp;

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        cin >> map[i];

        for(int j=0; j<c; j++) {
            if(map[i][j]=='J') {
                dist2[i][j] = 0;
                q2.push({i,j});
            }
            if(map[i][j]=='F') {
                dist1[i][j] = 0;
                q1.push({i,j});
            }
        }
    }

    fire_bfs();
    jihun_bfs();

    return 0;
}