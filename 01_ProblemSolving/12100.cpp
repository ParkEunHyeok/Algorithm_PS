#include <iostream>
using namespace std;

int n, mx=0;
int board1[21][21];
int board2[21][21];

void rotate() {
    int tmp[21][21];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            tmp[i][j] = board2[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            board2[i][j] = tmp[n-1-j][i];
        }
    }
}

void tilt(int dir) {
    while(dir--) rotate();
    for(int i=0; i<n; i++) {
        int tilted[21]={};
        int idx = 0;
        for(int j=0; j<n; j++) {
            if(board2[i][j]==0) continue;
            else if(tilted[idx]==0)
                tilted[idx] = board2[i][j];
            else if(tilted[idx]==board2[i][j]) {
                tilted[idx] *= 2;
                idx++;
            }
            else {
                idx++;
                tilted[idx] = board2[i][j];
            }
        }
        for(int j=0; j<n; j++)
            board2[i][j] = tilted[j];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board1[i][j];
        }
    }

    for(int tmp=0; tmp<1024; tmp++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        int d = tmp;
        for(int i=0; i<5; i++) {
            int dir = d % 4;
            d /= 4;
            tilt(dir);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                mx = max(mx, board2[i][j]);
            }
        }
    }

    cout << mx;
    return 0;
}