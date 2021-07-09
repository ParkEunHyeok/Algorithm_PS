#include <iostream>
#include <cstring>
using namespace std;

// Algorithm : DFS, Backtracking
// Logic : (0,0)을 방문처리한 후 DFS 실행.
//         DFS를 돌릴 때 방문 안했으면 돌리고,
//         돌린 후에 방문 false로 바꾸기 (백트래킹)

int r, c;
char map[22][22];
bool alphabet[28];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int result;

void dfs(int y, int x, int depth) {
    result = max(result, depth);

    for(int i=0; i<4; i++) {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if(nextY<0 || nextX<0 || nextY>=r || nextX>=c) continue;
        
        if(!alphabet[map[nextY][nextX]-'A']) {
            alphabet[map[nextY][nextX]-'A'] = true;
            dfs(nextY, nextX, depth+1);
            alphabet[map[nextY][nextX]-'A'] = false;
        }
    }
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

    alphabet[map[0][0]-'A'] = true;
    dfs(0,0,1);

    cout << result;
    return 0;
}