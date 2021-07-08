#include <iostream>
using namespace std;

int n, m, k;
int result = 0;
int map[105][105];
bool visited[105][105];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int y, int x, int size) {
    visited[y][x] = true;
    
    for(int i=0; i<4; i++) {
        int next_y = y + dir[i][0];
        int next_x = x + dir[i][1];

        if(next_x<1 || next_x>m || next_y<1 || next_y>n) continue;
        if(!visited[next_y][next_x] && map[next_y][next_x]) {
            size++;
            dfs(next_y, next_x, size);
        }
    }

    result = max(result, size);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(!visited[i][j] && map[i][j]) {
                dfs(i,j,1);
            }
        }
    }
        
    cout << result;
    return 0;
}