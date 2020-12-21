#include <iostream>
#include <queue>

using namespace std;

int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
queue<pair<int, int>> q;
int map[1004][1004] = {2,};
int riped=0, not_riped=0, notomato=0;
int day;

int bfs() {
    int day = 0;

    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            int current_y = q.front().first;
            int current_x = q.front().second;
            q.pop();

            for(int j=0; j<4; j++) {
                int next_y = current_y + dir[j][0];
                int next_x = current_x + dir[j][1];

                if(map[next_y][next_x] == 0) {
                    not_riped--;
                    map[next_y][next_x]=1;
                    q.push(make_pair(next_y, next_x));
                }
            }

            // 모든 토마토를 익혔을 경우
            if(not_riped==0 && q.size()==0) return day;
            // 더 이상 익을 토마토가 없을 경우
            else if(not_riped!=0 && q.size()==0) return -1;
        }
        day++;
    }
    return -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int condition;
            cin >> condition;
            map[i+1][j+1] = condition;

            if(condition==1) {
                q.push(make_pair(i+1, j+1));
                riped++;
            }
            if(condition==0) {
                not_riped++;
            }
            if(condition==-1) {
                notomato++;
            }
        }
    }

    // 모든 토마토가 익어있거나, 익은 토마토가 없는 경우 : 예외처리
    if((m*n-notomato)==riped) {
        printf("0");
        return 0;
    }

    printf("%d", bfs());
    return 0;
}