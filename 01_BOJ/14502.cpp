#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Algorithm : BFS, Brute Force
// Logic : 모든 칸을 돌면서 벽을 세 개 설치하고, BFS 돌리기
// 0:빈칸, 1:벽, 2:바이러스

int n, m;
int map[12][12];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int result;

void bfs() {
    int expr[12][12] = {0,};
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        expr[i][j] = map[i][j];
    }

    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        if(expr[i][j]==2) q.push({i,j});
    }

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(nextY<0 || nextX<0 || nextY>=n || nextX>=m) continue;
            if(expr[nextY][nextX]==0) {
                q.push({nextY, nextX});
                expr[nextY][nextX] = 2;
            }
        }
    }

    int empty_cnt = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        if(expr[i][j]==0) empty_cnt++;
    }
    result = max(result, empty_cnt);
}

void build_wall(int count) {
    if(count==3) {
        bfs();
        return;
    }

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        if(map[i][j]==0) {
            map[i][j] = 1;
            build_wall(count+1);
            map[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int status;
            cin >> status;
            map[i][j] = status;
        }
    }

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        if(map[i][j]==0) {
            map[i][j] = 1;
            build_wall(1);
            map[i][j] = 0;
        }
    }

    cout << result;
    return 0;
}