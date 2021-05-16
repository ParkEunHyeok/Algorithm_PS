#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


// cheeze:3, premelt:2, air:1, hole:0
int y, x;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int map[102][102];
bool visited[102][102];
int lastCnt, day;

bool AllAir() {
    int cnt = 0;
    for(int i=0; i<y; i++) {
        for(int j=0; j<x; j++) {
            if(map[i][j]>1) cnt++;
        }
    }
    if(cnt==0) return true;
    lastCnt = cnt;
    return false;
}

void AirMark() {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int> > q;
    q.push(make_pair(0,0));

    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];

            if(0<=nextY && nextY<y && 0<=nextX && nextX<x) {
                if(!visited[nextY][nextX] &&
                    (map[nextY][nextX]==0 || map[nextY][nextX]==1)) {
                        map[nextY][nextX] = 1;
                        q.push(make_pair(nextY, nextX));
                        visited[nextY][nextX] = true;
                }
            }
        }
    }
}

void PreMeltMark() {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];

            if(0<=nextY && nextY<y && 0<=nextX && nextX<x) {
                if(!visited[nextY][nextX]) {
                    if(map[nextY][nextX]==3) {
                        map[nextY][nextX] = 2;
                        visited[nextY][nextX] = true;
                        continue;
                    }
                    if(map[nextY][nextX]==1) {
                        visited[nextY][nextX] = true;
                        q.push(make_pair(nextY, nextX));
                    }
                }
            }
        }
    }
}

void PreMeltClear() {
    for(int i=0; i<y; i++) {
        for(int j=0; j<x; j++) if(map[i][j]==2) {
            map[i][j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> y >> x;
    for(int i=0; i<y; i++) {
        for(int j=0; j<x; j++) {
            int num;
            cin >> num;
            if(num==1) map[i][j] = 3;
            else map[i][j] = 0;
        }
    }

    while(!AllAir()) {
        AirMark();
        PreMeltMark();
        PreMeltClear();
        day++;
    }

    cout << day << "\n" << lastCnt;
    return 0;
}