#include <iostream>
using namespace std;

int r, c;
int map[252][252];
bool visited[252][252];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int o, v;
int Ocnt, Vcnt;

void dfs(int y, int x) {
    visited[y][x] = true;

    for(int i=0; i<4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if(nextY<0 || nextX<0 || nextY>=r || nextX>=c) continue;
        if(!visited[nextY][nextX]) {
            if(map[nextY][nextX]==1) {  // 양
                o++;
                dfs(nextY, nextX);
            }
            else if(map[nextY][nextX]==2) { // 늑대
                v++;
                dfs(nextY, nextX);
            }
            else if(map[nextY][nextX]==0) { // 공백
                dfs(nextY, nextX);
            }
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        string temp;
        cin >> temp;
        for(int j=0; j<c; j++) {
            if(temp[j]=='.') map[i][j] = 0;
            else if(temp[j]=='o') map[i][j] = 1;
            else if(temp[j]=='v') map[i][j] = 2;
            else map[i][j] = map[i][j] = 3;
        }
    }

    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        if(!visited[i][j]) {
            if(map[i][j]==1) {
                o = 1;
                v = 0;
                dfs(i, j);
            }
            else if(map[i][j]==2) {
                o = 0;
                v = 1;
                dfs(i, j);
            }

            if(o>v) Ocnt += o;
            else Vcnt += v;
            o = 0, v = 0;
        }
    }

    cout << Ocnt << " " << Vcnt;
    return 0;
}