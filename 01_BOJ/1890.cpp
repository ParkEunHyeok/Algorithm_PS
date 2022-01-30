#include <iostream>
#define ll long long
using namespace std;

int n;
ll result = 0;
int map[102][102];
ll cache[102][102];

ll jump(int y, int x) {
    if(y>=n || x>=n) return 0;
    if(y==n-1 && x==n-1) return 1;

    ll& ret = cache[y][x];
    if(ret != -1) return ret;

    if(map[y][x]==0) return 0;
    return ret = (jump(y+map[y][x], x) + jump(y, x+map[y][x]));
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

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cache[i][j] = -1;
        }
    }

    cout << jump(0,0);
    return 0;
}