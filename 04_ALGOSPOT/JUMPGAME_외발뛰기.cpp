#include <iostream>
#include <cstring>
using namespace std;

int n;
int map[102][102], cache[102][102];

int jump(int y, int x) {
    if(y>=n || x>=n) return 0;
    if(y==n-1 && x==n-1) return 1;

    int& ret = cache[y][x];
    if(ret!=-1) return ret;

    int dist = map[y][x];
    return ret = (jump(y+dist, x) || jump(y, x+dist));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    while(c--) {
        cin >> n;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> map[i][j];
            }
        }
        memset(cache, -1, sizeof(cache));

        if(jump(0,0)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}