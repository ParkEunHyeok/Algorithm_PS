#include <iostream>
using namespace std;

int map[11][11];
int flag = false;

void backtracking(int cnt) {
    if(flag) return;
    
    if(cnt==81) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << map[i][j];
            }
            cout << "\n";
        }
        flag = true;
        return;
    }

    int y = cnt / 9;
    int x = cnt % 9;

    if(map[y][x]!=0) backtracking(cnt+1);
    else {
        for(int i=1; i<=9; i++) {
            bool visit = true;

            for(int j=0; j<9; j++) {
                // 같은 행, 열에 숫자 중복하는지 확인
                if(map[y][j]==i || map[j][x]==i) {
                    visit = false;
                    break;
                }
            }
            if(!visit) continue;

            // 3X3 square에서 숫자 중복하는지 확인
            int squareY = (y/3) * 3;
            int squareX = (x/3) * 3;
            for(int j=squareY; j<squareY+3; j++) {
                for(int k=squareX; k<squareX+3; k++) {
                    if(map[j][k]==i) {
                        visit = false;
                        break;
                    }
                }
                if(!visit) break;
            }

            // 중복하지 않는다면 재귀 돌림
            if(visit) {
                map[y][x] = i;
                backtracking(cnt+1);
                map[y][x] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cnt = 0;

    for(int i=0; i<9; i++) {
        string str;
        cin >> str;
        for(int j=0; j<9; j++) {
            map[i][j] = str[j] - '0';
            cnt++;
        }
    }

    backtracking(0);
    return 0;
}