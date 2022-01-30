#include <iostream>
#include <vector>
using namespace std;

int n, m, res;
// 방향 순서 : 위 오른쪽 아래 왼쪽
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int map1[10][10], map2[10][10];
bool cam[10][10][4];
vector<pair<int, int> > cctv;
vector<int> angle;

void copy() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            map2[i][j] = map1[i][j];
        }
    }
}

void blindspot() {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map2[i][j]==0) cnt++;
        }
    }
    res = min(res, cnt);
}

void upd(int y, int x, int d) {
    while(1) {
        y += dir[d][0];
        x += dir[d][1];

        if(y<0 || y>=n || x<0 || x>=m) return;
        if(map2[y][x]==6) return;
        if(map2[y][x]!=0) continue;

        map2[y][x] = 7;
    }
}

void dfs(int cnt) {
    if(cnt==cctv.size()) {
        for(int i=0; i<angle.size(); i++) {
            int y = cctv[i].first;
            int x = cctv[i].second;

            for(int j=0; j<4; j++) {
                if(cam[y][x][j]) {
                    upd(y, x, (angle[i]+j)%4);
                }
            }
        }

        blindspot();
        copy();
        return;
    }

    for(int i=0; i<4; i++) {
        angle.push_back(i);
        dfs(cnt+1);
        angle.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map1[i][j];

            if(1<=map1[i][j] && map1[i][j]<=5)
                cctv.push_back({i, j});
            
            if(map1[i][j]==1) {
                cam[i][j][0] = true;
            }
            else if(map1[i][j]==2) {
                cam[i][j][0] = true;
                cam[i][j][2] = true;
            }
            else if(map1[i][j]==3) {
                cam[i][j][0] = true;
                cam[i][j][1] = true;
            }
            else if(map1[i][j]==4) {
                cam[i][j][0] = true;
                cam[i][j][1] = true;
                cam[i][j][2] = true;
            }
            else if(map1[i][j]==5) {
                cam[i][j][0] = true;
                cam[i][j][1] = true;
                cam[i][j][2] = true;
                cam[i][j][3] = true;
            }
        }
    }

    res = n*m;
    copy();
    dfs(0);

    cout << res;
    return 0;
}