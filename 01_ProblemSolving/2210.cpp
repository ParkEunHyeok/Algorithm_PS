#include <iostream>
#include <set>
using namespace std;

int arr[6][6];
set<int> s;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int y, int x, int num, int cnt) {
    if(cnt==5) {
        s.insert(num);
        return;
    }
    
    for(int i=0; i<4; i++) {
        int nextY = arr[y][x] + dir[i][0];
        int nextX = arr[y][x] + dir[i][1];
        if(nextX>=0 && nextY>=0 && nextX<5 && nextY<5) {
            dfs(nextY, nextX, num*10+arr[nextY][nextX], cnt+1);
        }
    }
}

int main() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            dfs(i, j, arr[i][j], 0);
        }
    }

    cout << s.size();
    return 0;
}