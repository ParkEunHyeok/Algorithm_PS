#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
queue<pair<int, int>> q;
int map[1005][1005];
int riped=0, not_riped=0, notomato=0;

void bfs(void) {
    //int day = 1;    

    while(!q.empty()) {
        int size = q.size();
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for(int j=0; j<4; j++) {
            int next_y = current_y + dir[j][0];
            int next_x = current_x + dir[j][1];

            if(map[next_y][next_x] == 0) {
                not_riped--;
                map[next_y][next_x] = map[current_y][current_x] + 1;
                q.push(make_pair(next_y, next_x));
            }
        }
        /*
        // 모든 토마토를 익혔을 경우
        if(q.size()==0 && not_riped==0) return day;
        // 더 이상 익을 토마토가 없을 경우
        else if(q.size()==0 && not_riped!=0) return -1;
        */
    }
    //return -1;
}

int main() {
    memset(map, -1, sizeof(map));

    int m, n;
    cin >> m >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];

            if(map[i][j]==1) {
                q.push(make_pair(i, j));
                riped++;
            }
            if(map[i][j]==0) {
                not_riped++;
            }
            if(map[i][j]==-1) {
                notomato++;
            }
        }
    }

    int result = -1;
    // 모든 토마토가 익어있거나, 익은 토마토가 없는 경우 : 예외처리
    if((m*n-notomato)==riped) {
        printf("0");
        return 0;
    } else {
        bfs();

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(map[i][j]==0) {
                    printf("-1");
                    return 0;
                }
                result = max(result, map[i][j]);
            }
        }
        printf("%d", result-1);
    }

    return 0;
}