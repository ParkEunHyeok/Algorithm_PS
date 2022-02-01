#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, k, l;
bool visited[102][102];
bool apple[102][102];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
queue<pair<int, int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<k; i++) {
        int y, x;
        cin >> y >> x;
        apple[y-1][x-1] = true;
    }

    cin >> l;
    deque<pair<int, char>> turn;

    for(int i=0; i<l; i++) {
        int x;
        char c;
        cin >> x >> c;
        turn.push_back({x,c});
    }

    int res=0, dir=0;
    deque<pair<int, int>> snake;
    snake.push_back({0,0});
    visited[0][0] = true;

    while(1) {
        res++;
        pair<int, int> prev = snake.back();
        pair<int, int> cur = {prev.first+dy[dir], prev.second+dx[dir]};

        if(cur.first<0 || cur.first>=n || cur.second<0 || cur.second>=n) break;
        if(visited[cur.first][cur.second]) break;

        visited[cur.first][cur.second] = true;
        snake.push_back(cur);

        if(apple[cur.first][cur.second]) {
            apple[cur.first][cur.second] = false;
        } else {
            pair<int, int> tail = snake.front();
            visited[tail.first][tail.second] = false;
            snake.pop_front();
        }

        // 방향 전환
        if(turn.size() && turn.front().first==res) {
            if(turn.front().second=='D') dir = (dir+1)%4;
            else dir = (dir+3)%4;
            turn.pop_front();
        }
    }

    cout << res;
    return 0;
}