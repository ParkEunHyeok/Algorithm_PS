#include <iostream>
#include <queue>
using namespace std;

int n;
const int INF = 987654321;
int map[402][402];
int visit[402][402];
int dir[8][2] = {{1,-2},{1,2},{-1,-2},{-1,2},{2,-1},{2,1},{-2,-1},{-2,1}};

void init() {
    for(int i=0; i<402; i++) {
        for(int j=0; j<402; j++) {
            map[i][j] = INF;
            visit[i][j] = 0;
        }
    }
}

int bfs(int x1, int y1, int x2, int y2) {
    queue<pair<int, int>> q;
    q.push(make_pair(y1, x1));
    map[y1][x1] = 0;

    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        if(curX==x2 && curY==y2) {
            return map[curY][curX];
        }

        for(int i=0; i<8; i++) {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];

            if(0<=nextX && nextX<n && 0<=nextY && nextY<n && visit[nextY][nextX]==0) {
                q.push(make_pair(nextY, nextX));
                visit[nextY][nextX] = 1;
                map[nextY][nextX] = min(map[nextY][nextX], map[curY][curX]+1);
            }
        }
    }
}

int main() {
    int cycle;
    cin >> cycle;
    for(int i=0; i<cycle; i++) {
        cin >> n;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        init();
        cout << bfs(x1,y1,x2,y2) << "\n";
    }

    return 0;
}