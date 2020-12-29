#include <iostream>
#include <cstring>
using namespace std;

int dir[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
int map[52][52];
int visit[52][52];

void dfs(int y, int x) {
    visit[y][x] = 1;

    for(int i=0; i<8; i++) {
        int next_y = y + dir[i][0];
        int next_x = x + dir[i][1];

        if(visit[next_y][next_x]==0 && map[next_y][next_x]==1) {
            dfs(next_y, next_x);
        }
    }
}

int main() {
    while(1) {
       int w, h;   // 섬의 너비, 높이
       cin >> w >> h;
       if(w==0 && h==0) break;

        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));

       for(int i=1; i<=h; i++) {
           for(int j=1; j<=w; j++) {
               cin >> map[i][j];
           }
       }

       int result = 0;
       for(int i=1; i<=h; i++) {
           for(int j=1; j<=w; j++) {
               if(visit[i][j]==0 && map[i][j]==1) {
                   dfs(i, j);
                   result ++;
               }
           }
       }

       cout << result << "\n";
    }
    
    return 0;
}