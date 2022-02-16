#include <iostream>
#include <cstring>
using namespace std;
#define ll long long

int n;
int map[34][34];
ll cache[3][34][34];

ll func(int dir, int y, int x) {
    if(y==n-1 && dir==1) return 0;
    if(x==n-1 && dir==0) return 0;
    if(y==n-1 && x==n-1) return 1; 

    ll& ret = cache[dir][y][x];
    if(ret!=-1) return ret;
    ret = 0;

    if(dir==0) {
        if(map[y][x+1]==0)
            ret += func(0, y, x+1);
        if(map[y+1][x+1]==0 && map[y+1][x]==0 && map[y][x+1]==0)
            ret += func(2, y+1, x+1);
    }
    else if(dir==1) {
        if(map[y+1][x]==0)
            ret += func(1, y+1, x);
        if(map[y+1][x+1]==0 && map[y+1][x]==0 && map[y][x+1]==0)
            ret += func(2, y+1, x+1);
    }
    else {
        if(map[y][x+1]==0)
            ret += func(0, y, x+1);
        if(map[y+1][x]==0)
            ret += func(1, y+1, x);
        if(map[y+1][x+1]==0 && map[y+1][x]==0 && map[y][x+1]==0)
            ret += func(2, y+1, x+1);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));

    cout << func(0, 0, 1);
    return 0;
}