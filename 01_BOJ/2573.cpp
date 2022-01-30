#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

// Algorithm : BFS
// Logic : 1.섬 개수 세기, BFS 사용
//         섬이 0개거나 2개보다 많으면 while문 빠져나오기
//         2.빙산 녹이기
//         모든 배열 돌면서 방향변수로 주변 빙산 체크
//         다 돌고 map에 적용
//         3.년도 카운트

int r, c;
int year = 0;
int map[302][302];
int sea[302][302];
bool visited[302][302];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool flag;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(nextY<0 || nextX<0 || nextY>=r || nextX>=c) continue;
            if(!visited[nextY][nextX] && map[nextY][nextX]) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
    }
}

void land_count() {
    int cnt = 0;
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        if(map[i][j]!=0 && !visited[i][j]) {
            bfs(i, j);
            cnt++;
        }
    }

    if(cnt==0) {
        cout << 0;
        flag = true;
    }
    if(cnt>=2) {
        cout << year;
        flag = true;
    }
}

void melt() {
    memset(sea, 0, sizeof(sea));

    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        if(map[i][j]!=0) {
            int cnt = 0;
            for(int k=0; k<4; k++) {
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];
                if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
                if(map[ny][nx]==0) cnt++;
            }
            sea[i][j] = cnt;
        }
    }

    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        if(map[i][j]!=0) {
            map[i][j] -= sea[i][j];
            if(map[i][j]<0) map[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }
    }

    while(1) {
        land_count();
        if(flag) break;

        melt();
        year++;
    }

    return 0;
}