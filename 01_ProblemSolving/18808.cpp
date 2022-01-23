#include <iostream>
using namespace std;

int n, m, k;
int r, c;
int laptop[42][42];
int sticker[12][12];

bool attach(int y, int x) {
    for(int i=0; i<r; i++) for(int j=0; j<c; j++)
    {
        if(laptop[y+i][x+j] && sticker[i][j]) {
            return false;
        }
    }
    for(int i=0; i<r; i++) for(int j=0; j<c; j++)
    {
        if(sticker[i][j]==1) {
            laptop[y+i][x+j] = 1;
        }
    }
    return true;
}

void rotate() {
    int tmp[12][12];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }
    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            sticker[i][j] = tmp[r-1-j][i];
        }
    }
    swap(r, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> sticker[i][j];
            }
        }

        for(int rot=0; rot<4; rot++) {
            bool flag = false;
            for(int i=0; i<=n-r; i++) {
                if(flag) break;
                for(int j=0; j<=m-c; j++) {
                    if(attach(i,j)) {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
            rotate();
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cnt += laptop[i][j];
        }
    }

    cout << cnt;
    return 0;
}