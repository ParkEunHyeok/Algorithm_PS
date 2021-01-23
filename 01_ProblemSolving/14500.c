#include <stdio.h>

int n, m;
int map[504][504];
int visited[504][504];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
// ㅏ, ㅜ, ㅓ, ㅗ
int ux[4][4] = {{0,0,1,0},{0,1,2,1},{0,1,1,1},{0,1,2,1}};
int uy[4][4] = {{0,1,1,2},{0,0,0,1},{0,-1,0,1},{0,0,0,-1}};
int result=0;

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

void dfs(int y, int x, int cnt, int sum) {
    if(cnt==4) {
        result = max(result, sum);
        return;
    }

    for(int i=0; i<4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if(nextX<1 || nextX>m || nextY<1 || nextY>n) continue;

        if(visited[nextY][nextX]==0) {
            visited[nextY][nextX] = 1;
            dfs(nextY, nextX, cnt+1, sum + map[nextY][nextX]);
            visited[nextY][nextX] = 0;
        }
    }
}

void find_u(int y, int x) {
    for(int i=0; i<4; i++) {
        int flag=1;
        int sum = 0;

        for(int j=0; j<4; j++) {
            int ty = y + uy[i][j];
            int tx = x + ux[i][j];

            if(tx<1 || tx>m || ty<1 || ty>n) {
                flag = 0;
                break;
            } else {
                sum += map[ty][tx];
            }
        }

        if(flag) {
            result = max(result, sum);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int num;
            scanf("%d", &num);
            map[i][j] = num;
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            visited[i][j] = 1;
            dfs(i, j, 1, map[i][j]);
            visited[i][j] = 0;

            find_u(i,j);
        }
    }

    printf("%d", result);
    return 0;
}