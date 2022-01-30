#include <iostream>
using namespace std;

int n, k, res=-1;
int map[52][52];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void func(int y, int x, int d, int cost) {
    if(y==n-1 && x==n-1) {
        res = cost;
        return;
    }

    int tile = map[y][x];

    if(tile==0) {
        if(d==0) d = 1;
        else d = 2;
    }
    else if(tile==1) {
        if(d==0) d = 3;
        else d = 2;
    }
    else if(tile==2) {
        if(d==2) d = 1;
        else d = 0;
    }
    else if(tile==3) {
        if(d==1) d = 0;
        else d = 3;
    }

    func(y+dir[d][0], x+dir[d][1], d, cost+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    func(0, 0, 1, 1);

    cout << res;
    return 0;
}