#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int arr[12][6];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool visited[12][6];
int btm[6];

int cntColor(int y, int x, int color) {
    int cnt = 1;
    queue<pair<int, int> > q;
    q.push({y, x});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if(ny<0 || ny>=12 || nx<0 || nx>=6) continue;
            if(!visited[ny][nx] && arr[ny][nx]==color) {
                visited[ny][nx] = true;
                q.push({ny, nx});
                cnt++;
            }
        }
    }

    return cnt;
}

void rmColor(int y, int x, int color) {
    queue<pair<int, int> > q;
    q.push({y, x});
    visited[y][x] = true;
    arr[y][x] = 0;
    btm[x]++;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if(ny<0 || ny>=12 || nx<0 || nx>=6) continue;
            if(!visited[ny][nx] && arr[ny][nx]==color) {
                btm[nx]++;
                arr[ny][nx] = 0;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void gravity() {
    for(int i=0; i<6; i++) {
        for(int k=0; k<btm[i]; k++) {
            for(int j=11; j>0; j--) {
                if(!arr[j][i])
                    swap(arr[j][i], arr[j-1][i]);
            }
        }
        btm[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int res = 0;

    for(int i=0; i<12; i++) {
        cin >> str;
        for(int j=0; j<6; j++) {
            if(str[j]=='R') arr[i][j] = 1;
            else if(str[j]=='G') arr[i][j] = 2;
            else if(str[j]=='B') arr[i][j] = 3;
            else if(str[j]=='P') arr[i][j] = 4;
            else if(str[j]=='Y') arr[i][j] = 5;
            else arr[i][j] = 0;
        }
    }

    bool flag = false;
    while(1) {
        for(int j=11; j>=0; j--) {
            for(int i=0; i<6; i++) {
                if(!visited[j][i] && arr[j][i]) {
                    visited[j][i] = true;
                    int adj = cntColor(j, i, arr[j][i]);
                    memset(visited, 0, sizeof(visited));

                    if(adj>=4) {
                        rmColor(j, i, arr[j][i]);
                        memset(visited, 0, sizeof(visited));
                        flag = true;
                    }
                }
            }
        }

        gravity();

        if(flag) {
            flag = false;
            res++;
        }
        else break;
    }
    
    cout << res;
    return 0;
}