#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
queue<pair<int, int>> q;
int map[104][104] = {0,};
int visit[104][104] = {0,};
int count = 0;

void bfs() {
    q.push(make_pair(1,1));
    visit[1][1] = 1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_y = y + dir[i][0];
            int next_x = x + dir[i][1];

            if(map[next_y][next_x]==1 && visit[next_y][next_x]==0) {
                visit[next_y][next_x] = 1;
                q.push(make_pair(next_y, next_x));
                map[next_y][next_x] = map[y][x] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            map[i+1][j+1] = str[j]-'0';
        }
    }

    bfs();
    printf("%d", map[n][m]);
    return 0;
}