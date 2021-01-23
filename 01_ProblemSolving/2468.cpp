#include <iostream>
#include <cstring>
using namespace std;

int map[102][102];
int visit[102][102];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int mx=0;   // 최대 높이

void init() {
    memset(visit, 0, sizeof(visit));
}

void dfs(int depth, int y, int x) {
    visit[y][x] = 1;

    for(int i=0; i<4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if(visit[nextY][nextX]==0 && map[nextY][nextX] > depth) {
            dfs(depth, nextY, nextX);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> map[i][j];
            mx = max(mx, map[i][j]);   
        }
    }

    int result = 0;
    // 비가 0만큼 내리는 것도 고려해야 함.
    for(int i=0; i<=mx; i++) {
        init();
        int count = 0;
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                if(map[j][k] <= i) visit[j][k] = 1;

                if(visit[j][k]==0) {
                    count++;
                    dfs(i, j, k);
                }
            }
        }
        result = max(result, count);
    }

    cout << result;
    return 0;
}