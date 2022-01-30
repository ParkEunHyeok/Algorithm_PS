#include <iostream>
using namespace std;

int n, m, r, c, d, res=0;
int map[52][52];

void rotate() {
    int tmp[52][52];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            tmp[i][j] = map[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            map[j][n-1-i] = tmp[i][j];
        }
    }
    swap(n, m);
}

void robot(int y, int x) {
    if(!map[y][x]) {
        res++;
        map[y][x] = 2;
    }

    for(int i=0; i<4; i++) {
        if(x-1>=0 && map[y][x-1]==0) {
            x--;
            rotate();
            robot(y, x);
            return;
        } else rotate();
    }
    
    if(y+1<n && map[y+1][x]==1) return;
    else robot(y+1, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<d; i++) rotate();
    robot(r, c);
    cout << res;
    return 0;
}