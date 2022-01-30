#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int map[102][102];
int visit[102][102];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int y, int x) {
    visit[y][x] = 1;
    for(int i=0; i<4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if(visit[nextY][nextX]==0 && map[y][x]==map[nextY][nextX]) {
            dfs(nextY, nextX);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            if(str[j]=='R') {   // 빨
                map[i+1][j+1] = 1;
            }
            else if(str[j]=='G') {  // 초
                map[i+1][j+1] = 2;
            }
            else {  // 파
                map[i+1][j+1] = 3;
            }
        }
    }

    int none_result = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(visit[i][j]==0) {
                dfs(i, j);
                none_result++;
            }
        }
    }
    memset(visit, 0, sizeof(visit));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]==2) {
                map[i][j] = 1;
            }
        }
    }
    int exist_result = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(visit[i][j]==0) {
                dfs(i, j);
                exist_result++;
            }
        }
    }

    printf("%d %d", none_result, exist_result);
    return 0;
}