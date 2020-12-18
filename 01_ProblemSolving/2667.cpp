#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int map[30][30] = {0,};
int visit[30][30] = {0,};
int cnt = 0;
int result[25*25+1];
int result_index = 0;

void dfs(int y, int x) {
    visit[y][x] = 1;
    cnt++;
    
    // 오른쪽 칸과 이어져 있는 경우
    if(map[y][x+1]==1 && visit[y][x+1]==0) {
        dfs(y,x+1);
    }
    // 왼쪽 칸과 이어져 있는 경우
    if(map[y][x-1]==1 && visit[y][x-1]==0) {
        dfs(y,x-1);
    }
    // 위 칸과 이어져 있는 경우
    if(map[y-1][x]==1 && visit[y-1][x]==0) {
        dfs(y-1, x);
    }
    // 아래 칸과 이어져 있는 경우
    if(map[y+1][x]==1 && visit[y+1][x]==0) {
        dfs(y+1, x);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<str.length(); j++) {
            if(str[j]=='1') {
                map[i+1][j+1] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]==1 && visit[i][j]==0) {
                dfs(i,j);
                result[result_index++] = cnt;
                cnt = 0;
            }
        }
    }

    sort(result, result + result_index);
    printf("%d\n", result_index);
    for(int i=0; i<result_index; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}