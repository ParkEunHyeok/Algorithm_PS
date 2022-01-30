#include <iostream>
using namespace std;

int n, result=0;
bool arr[16][16]={false,};

bool check(int i, int cnt) {    // 행의 왼쪽만 보면 됨.
    for(int j = 0; j < cnt; j++) {  // 행에서 겹치는지
        if (arr[i][j]) return false;
    }
    for(int x=cnt-1, y=i-1; y>=0; x--,y--) {    // 왼쪽 위 대각선으로 겹치는지
        if(arr[y][x]) return false;
    }
    for(int x=cnt-1, y=i+1; y<n; x--,y++) { // 왼쪽 아래 대각선으로 겹치는지
        if(arr[y][x]) return false;
    }
    return true;
}

void dfs(int x) { // 이차원 배열에서 x값
    if(x==n) result++;
    else {
        for(int i=0; i<n; i++) {    // i는 이차원 배열에서 y값
            // 0번째 행부터 장기를 놓을 수 있는 열을 다 탐색
            if (!arr[i][x] && check(i, x)) {
            arr[i][x] = true;
            dfs(x+1);
            arr[i][x] = false;
        }
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << result;
    return 0;
}