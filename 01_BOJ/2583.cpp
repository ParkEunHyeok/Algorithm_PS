#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int map[102][102] = {0,};
vector<int> v;
queue<pair<int, int>> q;

void bfs(void) {
    int cnt = 0;
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];

            if(map[nextY][nextX]==1) {
                map[nextY][nextX] = 2;
                q.push(make_pair(nextY, nextX));
                cnt++;
            }
        }
    }
    if(cnt==0) cnt++;
    v.push_back(cnt);
}

int main() {
    int m, n, k;    // 세로, 가로, 빈칸의 개수
    cin >> m >> n >> k;

    for(int i=0; i<n; i++) {
        map[0][i] = -1;
        map[m+1][i] = -1;
    }
    for(int i=0; i<m; i++) {
        map[i][0] = -1;
        map[i][n+1] = -1;
    }

    for(int i=0; i<k; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(int j=y1+1; j<=y2; j++) {
            for(int k=x1+1; k<=x2; k++) {
                map[j][k] = -1;
            }
        }
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]==0) map[i][j] = 1;
        }
    }

    int result = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]==1) {
                q.push(make_pair(i, j));
                result++;
                bfs();
            }
        }
    }

    sort(v.begin(), v.end());
    cout << result << "\n";
    for(int i=0; i<v.size(); i++) {
        printf("%d ", v[i]);
    }

    return 0;
}