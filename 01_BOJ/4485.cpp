#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> piii;
#define INF 1987654321

int map[128][128];
int dist[128][128];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cnt = 0;
    while(1) {
        cnt++;
        int n;
        cin >> n;
        if(n==0) break;
        else {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    cin >> map[i][j];
                    dist[i][j] = INF;
                }
            }

            priority_queue<piii, vector<piii>, greater<piii>> pq;
            dist[0][0] = map[0][0];
            pq.push({map[0][0], {0,0}});

            while(!pq.empty()) {
                int cost = pq.top().first;
                int y = pq.top().second.first;
                int x = pq.top().second.second;
                pq.pop();

                for(int i=0; i<4; i++) {
                    int ny = y + dir[i][0];
                    int nx = x + dir[i][1];
                    if(ny<0 || ny>=n || nx<0 || nx>=n) continue;

                    int nCost = cost + map[ny][nx];
                    if(dist[ny][nx] > nCost) {
                        dist[ny][nx] = nCost;
                        pq.push({nCost, {ny, nx}});
                    }
                }
            }

            cout << "Problem " << cnt << ": " << dist[n-1][n-1] << "\n";
        }
    }

    return 0;
}