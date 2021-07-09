#include <iostream>
#include <cstring>
using namespace std;

int r, c;
char map[22][22];
bool visited[22][22];
bool alphabet[22];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int result;

int init() {
    memset(visited, 0, sizeof(visited));
    memset(alphabet, 0, sizeof(alphabet));
}

int dfs(int y, int x) {
    int depth = 1;
    visited[y][x] = true;
    alphabet[map[y][x]-'A'] = true;

    for(int i=0; i<4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if(nextY<0 || nextX<0 || nextY>=r || nextY>=c) continue;
        if(alphabet[map[nextY][nextX]-'A']) continue;
        if(!visited[nextY][nextX]) {
            depth += dfs(nextY, nextX);
        }
    }

    return depth;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c; 
    for(int i=0; i<r; i++) {
        string temp;
        cin >> temp;

        for(int j=0; j<c; j++) {
           map[i][j] = temp[j];
        }
    }
    
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        init();
        int temp = dfs(i, j) - 1;
        if (result < temp)
        {
           result = temp;
           cout << i << ' '<< j << '\n'; 
        }
        // result = max(result, dfs(i,j)-1);
    }

    cout << result;
    return 0;
}