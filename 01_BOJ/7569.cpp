#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// Algorithm : BFS
// Logic : bfs에서 익지 않은 토마토를 보면
//         익은 토마토의 값 +1만큼 대입,
//         bfs를 돌고 나서 map에서 토마토의 값의 최댓값-1이
//         모든 토마토가 익은 날이 된다.

queue<pair<pair<int, int>, int>> q;
int map[104][104][104];
int r, c, h;    // 세로, 가로, 높이
int riped=0, not_riped=0, notomato=0;
int dir[6][3] = {{0,1,0},{0,-1,0},{0,0,1},
                {0,0,-1},{1,0,0},{-1,0,0}};

void bfs() {
    while(!q.empty()) {
        int curH = q.front().first.first;
        int curR = q.front().first.second;
        int curC = q.front().second;
        q.pop();

        for(int i=0; i<6; i++) {
            int nextH = curH + dir[i][0];
            int nextR = curR + dir[i][1];
            int nextC = curC + dir[i][2];

            if(map[nextH][nextR][nextC] == 0) {
                not_riped--;
                map[nextH][nextR][nextC] = map[curH][curR][curC] + 1;
                q.push(make_pair(make_pair(nextH, nextR), nextC));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(map, -1, sizeof(map));

    cin >> c >> r >> h;
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=r; j++) {
            for(int k=1; k<=c; k++) {
                int temp;
                cin >> temp;
                if(temp==-1) {  // -1:들어있지 않음
                    map[i][j][k] = temp;
                    notomato++;
                }
                else if(temp==0) {  // 0:익지 않음
                    map[i][j][k] = temp;
                    not_riped++;
                }
                else if(temp==1) {  // 1:익음
                    q.push(make_pair(make_pair(i,j),k));
                    map[i][j][k] = temp;
                    riped++;
                }
            }
        }
    }

    int result = -1;
    if(not_riped==0) cout << 0;
    else {
        bfs();

        for(int i=1; i<=h; i++) {
            for(int j=1; j<=r; j++) {
                for(int k=1; k<=c; k++) {
                    if(map[i][j][k]==0) {
                        cout << -1;
                        return 0;
                    }
                    result = max(result, map[i][j][k]);
                }
            }
        }
        cout << result-1;
    }

    return 0;
}