#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int marking;
vector<int> groups;
int map[1004][1004];    // 입력 맵
bool visited[1004][1004];    // 방문
int group[1004][1004];  // marking 표시
int result[1004][1004]; // 결괏값
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y,x});
    visited[y][x] = true;
    group[y][x] = marking;
    int cnt = 1;

    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];

            if(nextY<0 || nextX<0 || nextY>=n || nextX>=m) continue;
            if(map[nextY][nextX]==0 && !visited[nextY][nextX]) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
                group[nextY][nextX] = marking;
                cnt++;
            }
        }
    }

    groups.push_back(cnt);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    groups.push_back(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<m; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==0 && visited[i][j]==false) {
                marking++;
                bfs(i, j);
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==1) {
                vector<int> list;
                int score = 1;
                
                for(int k=0; k<4; k++) {
                    int nextY = i + dir[k][0];
                    int nextX = j + dir[k][1];

                    if(nextY<0 || nextX<0 || nextY>=n || nextX>=m) continue;
                    if(map[nextY][nextX]==0) {
                        list.push_back(group[nextY][nextX]);
                    }
                }
                
                sort(list.begin(), list.end());
                list.erase(unique(list.begin(), list.end()), list.end());
            
                for(int k=0; k<list.size(); k++) {
                    score += groups[list[k]];
                }

                result[i][j] = score%10;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}