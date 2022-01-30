#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, x, y, k, dir;
    int map[22][22];
    int dice[6] = {0,};

    cin >> n >> m >> y >> x >> k;  
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    while(k--) {
        cin >> dir;

        if(dir==1) {
            if(x+1>=m) continue;
            x++;

            int tmp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = tmp;
        }
        else if(dir==2) {
            if(x-1<0) continue;
            x--;

            int tmp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = tmp;
        }
        else if(dir==3) {
            if(y-1<0) continue;
            y--;

            int tmp = dice[1];
            dice[1] = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = tmp;
        }
        else {
            if(y+1>=n) continue;
            y++;

            int tmp = dice[5];
            dice[5] = dice[4];
            dice[4] = dice[0];
            dice[0] = dice[1];
            dice[1] = tmp;
        }

        if(map[y][x]==0) {
            map[y][x] = dice[5];
        } else {
            dice[5] = map[y][x];
            map[y][x] = 0;
        }

        cout << dice[0] << "\n";
    }

    return 0;
}