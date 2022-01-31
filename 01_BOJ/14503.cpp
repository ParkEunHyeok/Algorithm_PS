#include <iostream>
using namespace std;

int n, m, y, x, d, res=0;
int map[52][52];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> y >> x >> d;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    while(1) {
        if(map[y][x]==0) res++;
        map[y][x] = 2;

        bool cleanable = false;
        for(int i=0; i<4; i++) {
            d = (d+3)%4;
            if(map[y+dy[d]][x+dx[d]]==0) {
                y += dy[d];
                x += dx[d];
                cleanable = true;
                break;
            }
        }
        if(cleanable) continue;

        // 마지막 행, 열은 벽이므로 범위 처리 불필요
        if(map[y-dy[d]][x-dx[d]]==1) break;
        x -= dx[d];
        y -= dy[d];
    }

    cout << res;
}