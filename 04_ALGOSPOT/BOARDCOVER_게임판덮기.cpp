#include <iostream>
#include <cstring>
using namespace std;

int n, m;
bool board[22][22];

// 주어진 칸을 덮을 수 있는 네 가지 방법
// 블록을 구성하는 세 칸의 상대적 위치 (dy, dx)의 목록
const int coverType[4][3][2] = {
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,-1}},
    {{0,0},{1,0},{1,1}}
};

// board의 (y, x)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다.
// delta = 1이면 덮고, -1이면 덮었던 블록을 없앤다.
// 만약 블록이 제대로 덮이지 않은 경우 (게임판 밖으로 나가거나,
// 겹치거나, 검은 칸을 덮을 때) false를 반환한다.
bool set(int y, int x, int type, int delta) {
    bool ok = true;
    for(int i=0; i<3; i++) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if(ny<0 || ny>=n || nx<0 || nx>=m) ok = false;
        else if((board[ny][nx] += delta) > 1) ok = false;
    }
    return ok;
}

// board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다.
// board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
// board[i][j] = 0 아직 덮이지 않은 칸
int cover() {
    int y = -1, x = -1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!board[i][j]) {
                x = i;
                y = j;
                break;
            }
        }
        if(y!=-1) break;
    }
    // 모든 칸을 채운 경우
    if(y==-1) return 1;
    int ret = 0;
    for(int type=0; type<4; type++) {
        if(set(y, x, type, 1)) ret += cover();
        // 덮었던 블록을 치운다.
        set(y, x, type, -1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        string str;
        cin >> n >> m;

        int cnt = 0;
        for(int i=0; i<n; i++) {
            cin >> str;
            for(int j=0; j<m; j++) {
                if(str[j]=='#') board[i][j] = 1;
                else cnt++, board[i][j] = 0;
            }
        }

        if(cnt%3!=0) cout << 0 << "\n";
        else cout << cover() << "\n";
    }
    
    return 0;
}