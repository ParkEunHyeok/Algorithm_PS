#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int cheeze;
int map[102][102];
int visited[102][102];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<pair<pair<int, int>, int> > real_cheeze;
vector<pair<int, int>> melt_cheeze;
queue<pair<int, int>> cheezeQ;

void outside_air() {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int> > q;
    q.push({0,0});
    visited[0][0] = 1;
    map[0][0] = 3;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(0<=nextY && 0<=nextX && nextY<n && nextX<m) {
                if(!visited[nextY][nextX] && map[nextY][nextX]==4) {
                    map[nextY][nextX] = 3;
                    visited[nextY][nextX] = 1;
                    q.push({nextY, nextX});
                }
            }
        }
    }
}

void cheeze_condition() {
    melt_cheeze.clear();

    for(int i=0; i<real_cheeze.size(); i++) {
        int y = real_cheeze[i].first.first;
        int x = real_cheeze[i].first.second;
        if(real_cheeze[i].second==1) continue;

        int cnt = 0;
        for(int j=0; j<4; j++) {
            int nextY = y + dir[j][0];
            int nextX = x + dir[j][1];

            if(map[nextY][nextX]==3) cnt++;
        }

        if(cnt>=2) {
            real_cheeze[i] = {{y,x},1};
            melt_cheeze.push_back({y, x});
        }
    }

    for(int i=0; i<melt_cheeze.size(); i++) {
        int y = melt_cheeze[i].first;
        int x = melt_cheeze[i].second;
        map[y][x] = 3;
        cheezeQ.push({y,x});
    }
}

void air_refresh() {
    while(!cheezeQ.empty()) {
        int y = cheezeQ.front().first;
        int x = cheezeQ.front().second;
        cheezeQ.pop();

        for(int i=0; i<4; i++) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(0<=nextY && 0<=nextX && nextY<n && nextX<m) {
                if(!visited[nextY][nextX] && map[nextY][nextX]==4) {
                    map[nextY][nextX] = 3;
                    visited[nextY][nextX] = 1;
                    cheezeQ.push({nextY, nextX});
                }
            }
        }
    }
}

bool all_clear() {
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        if(map[i][j]==1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int temp;
            cin >> temp;
            if(temp==0) map[i][j] = 4;
            else{
                real_cheeze.push_back({{i,j},0});
                cheeze++;
                map[i][j] = 1;
            }
        }
    }

    int day = 0;
    int flag = false;
    outside_air();

    while(1) {
        if(all_clear()) break;
        cheeze_condition();
        air_refresh();
        day++;
    }
    cout << day;

    return 0;
}