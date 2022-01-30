#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int map[53][53] = {0,};
int visit[53][53] = {0,};

int bfs(int y, int x) {
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;
    int result = 0;

    q.push(make_pair(y,x));
    visit[y][x] = 1;

    while(!q.empty()) {
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_y = current_y + dir[i][0];
            int next_x = current_x + dir[i][1];

            result = max(result, visit[current_y][current_x]);

            if(map[next_y][next_x]=='L' && visit[next_y][next_x]==0) {
                q.push(make_pair(next_y, next_x));
                visit[next_y][next_x] = visit[current_y][current_x] + 1;
            }
        }
    }

    return result-1;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            map[i+1][j+1] = str[j];
        }
    }

    int mx = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(map[i][j]=='L') {
                mx = max(mx, bfs(i,j));
            }
        }
    }

    printf("%d", mx);
    return 0;
}